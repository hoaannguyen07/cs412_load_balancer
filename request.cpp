#include "request.hpp"

#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

Request::Request()
{
    this->generate_request();
}

void Request::generate_request()
{
    std::string ip_in = generate_random_ip();
    std::string ip_out = generate_random_ip();
    int duration = rand() % 501 + 10;

    this->m_ip_in = ip_in;
    this->m_ip_out = ip_out;
    this->m_duration = duration;
    
}

std::string Request::generate_random_ip()
{
    std::string result;

    int part1 = rand() % 256;
    int part2 = rand() % 256;
    int part3 = rand() % 256;
    int part4 = rand() % 256;

    result = std::to_string(part1) + '.' + std::to_string(part2) + '.' 
                + std::to_string(part3) + '.' + std::to_string(part4);
    
    return result;
}

std::string Request::to_string()
{
    std::string result = "Request: {\n\tIP in: " + this->m_ip_in 
                            + ",\n\tIP out: " + this->m_ip_out 
                            + ",\n\tduration: " + std::to_string(this->m_duration) 
                            + "\n}\n";
    return result;
}
