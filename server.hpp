#include "request.hpp"

#include <string>

#ifndef SERVER_HPP
#define SERVER_HPP

/**
 * @brief A class used to handle requests
 * 
 */
class Server
{
private:
    std::string name;
    Request* m_requestCurrentlyHandling = nullptr;
    int m_requestStartTime = -1;
    int m_requestEndTime = -1;

    bool isReadyToResolveRequest(int);
public:
    /**
     * @brief Construct a new Server object with a passed in name
     * 
     * @param serverName name of the created Server instance
     */
    Server(std::string serverName);
    ~Server();

    /**
     * @brief Check if the server is available to process a new request
     * 
     * @return true Server is available to process a new request
     * @return false Server is NOT available to process a new request
     */
    bool isAvailable();

    /**
     * @brief Assign a request to the server for handling
     * 
     * @param request The request the server is supposed to handle
     * @param curTime The current clock time
     */
    void assignRequest(Request* request, int curTime);

    /**
     * @brief Have the server attempt resolving the request.
     * If the Server instance is currently not processing any requests, a statement will be printed but nothing will happen
     * If the current time indicates that the request still has not finished processing, a statement will be printed but nothing will happen. 
     * If the current time indicates that the request can be finished, a summary of the server handling the request will be printed out and the server will prepare to handle the next request
     * 
     * @param curTime 
     */
    void attemptResolvingRequest(int curTime);

    /**
     * @brief Reset the server state to prepare to handle a new request. Ensure that the server will be available if it is not already.
     * 
     */
    void resetServer();

    /**
     * @brief Summarize the state of the server instance
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif // SERVER_HPP