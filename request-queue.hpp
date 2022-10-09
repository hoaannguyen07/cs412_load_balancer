
#ifndef REQUESTQUEUE_HPP
#define REQUESTQUEUE_HPP

#include "request.hpp"

#include <queue>
#include <string>

/**
 * @brief Class modeling a request queue that a load balancer would subscribe to in order to handle incoming requests
 * 
 */
class RequestQueue
{
private:
    std::queue<Request> m_requestQueue;
    int m_initQueueSize;
public:
    /**
     * @brief Construct a new Request Queue object with a preset amount of random requests already populating the queue
     * 
     * @param initRequestAmount Amount of initial random requests to be generated. Defaults to 500
     */
    RequestQueue(int initRequestAmount);
    ~RequestQueue() {};

    /**
     * @brief Get the next Request object. 
     * 
     * @details Will pop that request out from the queue as well. Get the Request at the front of the queue and pop that request from the queue. Returns the request that was at the front of the queue.
     * 
     * @return Request 
     */
    Request getNextRequest();

    /**
     * @brief Get request at the front of the queue
     * 
     * @return Request 
     */
    Request front();
    
    /**
     * @brief Add a new request into the Request Queue
     * 
     * @param newRequest The request to be added to the queue
     */
    void push(Request& newRequest);

    /**
     * @brief Pop the request currently at the front of the queue
     * 
     */
    void pop();

    /**
     * @brief Check if queue is empty or not
     * 
     * @retval true if queue is empty
     * @retval false if queue is NOT empty
     */
    bool empty();

    /**
     * @brief Get size of the request queue
     * 
     * @return int 
     */
    int size();

    /**
     * @brief Summarize the request queue in a nicely laid out string
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif // REQUESTQUEUE_HPP