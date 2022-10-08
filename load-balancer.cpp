#include "load-balancer.hpp"

LoadBalancer::LoadBalancer(int size)
{
    this->m_serverGroup = ServerGroup(size);
}

void LoadBalancer::updateServerStates(int curTime)
{
    /**
     * Passing in nullptr for "request" field will skip the assigning of request to a server
     * The updating of server clocks will stay the same
     */
    this->processNewRequestAndUpdateServerStates(nullptr, curTime);
}

bool LoadBalancer::processNewRequestAndUpdateServerStates(Request* request, int curTime)
{
    bool requestIsProcessing = false;

    for(int i = 0; i < this->m_serverGroup.size(); i++)
    {
        Server& curServer = this->m_serverGroup[i];

        /**
         * Can just call Server.attemptResolvingRequest() but that has some processing (including I/O)
         * which can be avoided if we know that there is nothing to resolve.
         * I/O is expensive at scale, so cutting back on that will save up on time and reduce
         * unnecessary I/Os to parse through when reading logs
         */
        if (!curServer.isAvailable())
        {
            curServer.attemptResolvingRequest(curTime);
        }

        if (request != nullptr && curServer.isAvailable() && !requestIsProcessing)
        {
            // std::cout << curServer.to_string();

            // std::cout << request->to_string();

            curServer.assignRequest(request, curTime);

            // std::cout << this->m_serverGroup[i].to_string();

            requestIsProcessing = true;
        }
    }

    return requestIsProcessing;
}

std::string LoadBalancer::to_string()
{
    return this->m_serverGroup.to_string();
}