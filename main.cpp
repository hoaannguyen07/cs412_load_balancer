#include "request.hpp"

#include <iostream>

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

int main()
{
    srand(time(NULL)); // seeding random number generator
    int num_cycles = 10000, num_servers = 10;
    Option chosen_option = handle_input(num_cycles, num_servers);

    Request* sample1 = new Request();
    Request* sample2 = new Request();

    std::cout << sample1->to_string() << sample2->to_string();
    return 0;
}