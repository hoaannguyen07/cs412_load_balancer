#include <iostream>
#include <string>

#ifndef REQUEST_HPP
#define REQUEST_HPP

/**
 * @brief Outlines a mock request a server would receive
 * 
 */
class Request
{
private:
    std::string m_ip_in;
    std::string m_ip_out;
    int m_duration;

    void generate_request();
    std::string generate_random_ip();
public:
    /**
     * @brief Construct a new Request object with random input & output IP address and random legnth the request takes to process
     * 
     */
    Request();
    ~Request() {};

    /**
     * @brief Puts the request in a nicely laid out string format for cout and debugging
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif // REQUEST_HPP

