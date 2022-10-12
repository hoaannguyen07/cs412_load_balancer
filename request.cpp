#include "request.hpp"

#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

Request::Request()
{
    this->generate_request();
}

Request::Request(const Request& request)
{
    this->m_ip_in = request.m_ip_in;
    this->m_ip_out = request.m_ip_out;
    this->m_duration = request.m_duration;
}

void Request::generate_request()
{
    std::string ip_in = generate_random_ip();
    std::string ip_out = generate_random_ip();
    int duration = rand() % (Request::MAX_DURATION - Request::MIN_DURATION + 1) + Request::MIN_DURATION;

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

int Request::getDuration()
{
    return this->m_duration;
}

std::string Request::to_string()
{
    std::string result = "Request: {\n\tIP in: " + this->m_ip_in 
                            + ",\n\tIP out: " + this->m_ip_out 
                            + ",\n\tduration: " + std::to_string(this->m_duration) 
                            + "\n}\n";
    return result;
}
