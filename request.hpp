#include <iostream>
#include <string>

#ifndef REQUEST_HPP
#define REQUEST_HPP

/**
 * @brief Outlines a mock request a server would receive
 * 
 * @param ip_in The IP address of the incoming request
 * @param ip_out The IP address that the server should send the request once it has formed a response
 * @param duration The amount of time this request should take to process
 */
class Request
{
private:
    std::string ip_in;
    std::string ip_out;
    int duration;

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

