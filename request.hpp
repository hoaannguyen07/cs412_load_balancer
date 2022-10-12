
#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>

/**
 * @brief Class modeling how a request to a server would look like
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
     * @brief Minimum duration a request can have
     */
    static const int MIN_DURATION = 10;
    /**
     * @brief Maximum duration a request can have
     */
    static const int MAX_DURATION = 100;
    /**
     * @brief Construct a new Request object with random input & output IP addresses and random duration the request would take to process
     * 
     * @details IP addresses use the IPv4 format, meaning the it uses the "x.x.x.x" format with each x being a value from 0 to 255. The duration of each request range is dependent on the MIN and MAX durations specified in this class.
     */
    Request();

    /**
     * @brief Construct a deep copy of a Request object
     * 
     * @param request Request that the instance wants a deep copy of
     */
    Request(const Request& request);
    ~Request() {};

    /**
     * @brief Get the amount of clock cycles it would take to resolve the request
     * 
     * @return int 
     */
    int getDuration();

    /**
     * @brief Summarize the request in a nicely laid out string in JSON format
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif // REQUEST_HPP

