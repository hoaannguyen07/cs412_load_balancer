
#ifndef LOADBALANCER_HPP
#define LOADBALANCER_HPP

#include "request.hpp"
#include "server-group.hpp"

#include <string>

/**
 * @brief Class modeling a load balancer used to assign requests to individual servers in server groups to distribute workloads appropriately
 * 
 * @details This class uses the round-robin method to assign requests to servers for processing. This means that the next available server handles the incoming request. Due to the simplicity of this load balancer, server groups consisting of servers with the same specs will be best for this load balancer because the speed at which a request can be processed will not vary. Assigning a request to a specific server will not slow down the server more than if it was assigned to another server.
 * 
 */
class LoadBalancer
{
private:
public:
    ServerGroup m_serverGroup;
    /**
     * @brief Construct a new Load Balancer object with an initial server group size
     * 
     * @param size Initial size of the server group the load balancer has acess to in order to distributed the workload
     */
    LoadBalancer(int size);
    ~LoadBalancer() {};

    /**
     * @brief Update the clock time for all server to finish up processing their requests if possible
     * 
     * @param curTime Current clock time
     */
    void updateServerStates(int curTime);

    /**
     * @brief Attempt to process a request and update the time for all servers to finish up processing their requests if possible
     * 
     * @details Update the current time for servers in the server group in order to resolve any requests a server has that can be reolved. Then, find an available server to handle the request being passed in
     * 
     * @param request Request that the load balancer needs to handle
     * @param curTime Current clock time
     * 
     * @retval true if request has been picked up by a server and is processing
     * @retval false if request has not been picked up yet OR request == nullptr (no request to process)
     */
    bool processNewRequestAndUpdateServerStates(Request* request, int curTime);

    std::string to_string();
};

#endif // LOADBALANCER_HPP