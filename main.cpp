#include "request.hpp"
#include "request-queue.hpp"
#include "server.hpp"
#include "server-group.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

enum Option {DEFAULT, CUSTOM, INVALID};

void output_parameters_of_load_balancer(int& num_cycles, int& num_servers)
{
    std::cout << "Starting off with " << num_cycles << " clock cycles and " << num_servers << " servers\n";
}

Option handle_input(int &num_cycles, int &num_servers)
{
    char option_char;
    Option option = INVALID;
    while(option == INVALID){    
        std::cout << "How would you like to run the Load Balancer? [d]efault or [c]ustom? ";
        std::cin >> option_char; 

        switch (option_char)
        {
            case 'd':
                option = DEFAULT;
                break;
            case 'c':
                option = CUSTOM;
                std::cout << "How many cycles do you want to run the Load Balancer for? ";
                std::cin >> num_cycles;
                std::cout << "How many servers do you want to start off with? ";
                std::cin >> num_servers;
                break;
            default:
                std::cout << "Invalid option. Please choose a valid options\n";
                break;
        }
    }
    output_parameters_of_load_balancer(num_cycles, num_servers);
    return option;
}

void testRequestQueue()
{
    RequestQueue requestQueue(5);

    Request randomRequest = Request();

    requestQueue.push(randomRequest);

    std::cout << requestQueue.getNextRequest().to_string() << requestQueue.getNextRequest().to_string();

    std::cout << requestQueue.to_string();
}

void testServer()
{
    Server server = Server("A");
    std::cout << server.to_string();

    Request request = Request();
    server.assignRequest(&request, 3);
    // std::cout << server.m_requestCurrentlyHandling->to_string();
    // server.attemptResolvingRequest(3 + server.m_requestCurrentlyHandling->getDuration() - 1);
    // server.attemptResolvingRequest(3 + server.m_requestCurrentlyHandling->getDuration());

}

void testServerGroup()
{
    ServerGroup serverGroup = ServerGroup(3);

    std::cout << serverGroup.to_string();

    std::cout << serverGroup[1].to_string();

    Request randomRequest = Request();

    Server& pickedServer = serverGroup[1];
    pickedServer.assignRequest(&randomRequest, 0);
    // std::cout << pickedServer.to_string();

    
    std::cout << serverGroup[1].to_string();

    pickedServer.attemptResolvingRequest(randomRequest.getDuration() - 1);
    pickedServer.attemptResolvingRequest(randomRequest.getDuration());
    std::cout << serverGroup[1].to_string();
}

int main()
{
    srand(time(NULL)); // seeding random number generator
    int num_cycles = 10000, num_servers = 10;
    // Option chosen_option = handle_input(num_cycles, num_servers);

    // testServer();
    testServerGroup();


    return 0;
}