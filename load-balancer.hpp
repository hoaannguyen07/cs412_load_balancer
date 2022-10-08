#include "request.hpp"
#include "server-group.hpp"

#include <string>

#ifndef LOADBALANCER_HPP
#define LOADBALANCER_HPP

/**
 * @brief Class used to assign requests to individual servers in server groups to distribute workloads appropriately
 * 
 * This class uses the Round-Robin method to assign requests to servers for processing. This means that the next available server handles the incoming request. Due to the simplicity of this load balancer, server groups consisting of servers with the same specs will be best for this load balancer because the speed at which a request can be processed will not vary. Assigning a request to a specific server will not slow down the server more than if it was assigned to another server.
 * 
 */
class LoadBalancer
{
private:
public:
    ServerGroup m_serverGroup;
    /**
     * @brief Construct a new Load Balancer object with an initial size
     * 
     * @param size 
     */
    LoadBalancer(int size);
    ~LoadBalancer() {};

    /**
     * @brief Update the clock time for all server to finish up processing their requests if possible
     * 
     * @param curTime 
     */
    void updateServerStates(int curTime);

    /**
     * @brief Attempt to process a request and update the time for all servers to finish up processing their requests if possible
     * 
     * Update the current time for servers in the server group in order to resolve any requests a server has that can be reolved. Then, find an available server to handle the request being passed in
     * 
     * @param request 
     * @param curTime 
     * @return true Request has been picked up by a server and is processing
     * @return false Request has not been picked up yet OR request == nullptr (no request to process)
     */
    bool processNewRequestAndUpdateServerStates(Request* request, int curTime);

    std::string to_string();
};

#endif // LOADBALANCER_HPP