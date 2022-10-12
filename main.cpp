#include "request.hpp"
#include "test-load-balancer.hpp"

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

enum Option {DEFAULT, CUSTOM, INVALID};

void output_parameters_of_load_balancer(int& num_cycles, int& num_servers)
{
    std::cout << "\nStarting off with [" << num_cycles << "] clock cycles, [" << num_servers << "] servers, and [" << num_servers * 2 << "] requests";
    std::cout << "\nEach request will take between [" << Request::MIN_DURATION << "] and [" << Request::MAX_DURATION << "] clock cycles to resolve.\n";
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
                std::cout << "How many clock cycles do you want to run the Load Balancer for? (default = 10,000)";
                std::cin >> num_cycles;
                std::cout << "How many servers do you want to start off with? (default = 10)";
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

/**
 * @brief Entry point into the Load Balancing simulation
 * 
 * @return int 
 */
int main()
{
    std::ofstream out("log.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    srand(time(NULL)); // seeding random number generator
    int num_cycles = 10000, num_servers = 10;
    Option chosen_option = handle_input(num_cycles, num_servers);

    TestLoadBalancer::simulateLoadBalancer(num_servers * 2, num_servers, num_cycles);

    std::cout.rdbuf(coutbuf); //reset to standard output again

    return 0;
}