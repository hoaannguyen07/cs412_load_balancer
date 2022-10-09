#include "test-load-balancer.hpp"

#include "request.hpp"
#include "request-queue.hpp"
#include "server.hpp"
#include "server-group.hpp"
#include "load-balancer.hpp"

#include <iostream>
#include <math.h>

void TestLoadBalancer::testRequestQueue()
{
    RequestQueue requestQueue(5);

    Request randomRequest = Request();

    requestQueue.push(randomRequest);

    std::cout << requestQueue.getNextRequest().to_string() << requestQueue.getNextRequest().to_string();

    std::cout << requestQueue.to_string();
}

void TestLoadBalancer::testServer()
{
    Server server = Server("A");
    std::cout << server.to_string();

    Request request = Request();
    server.assignRequest(&request, 3);
    // std::cout << server.m_requestCurrentlyHandling->to_string();
    // server.attemptResolvingRequest(3 + server.m_requestCurrentlyHandling->getDuration() - 1);
    // server.attemptResolvingRequest(3 + server->getDuration());

}

void TestLoadBalancer::testServerGroup()
{
    ServerGroup serverGroup;
    serverGroup = ServerGroup(3);

    std::cout << serverGroup.to_string();

    std::cout << serverGroup[1].to_string();

    Request randomRequest = Request();

    Server& pickedServer = serverGroup[1];
    pickedServer.assignRequest(&randomRequest, 0);
    // std::cout << pickedServer.to_string();

    
    std::cout << serverGroup[1].to_string();

    pickedServer.attemptResolvingRequest(randomRequest.getDuration() - 1);
    pickedServer.attemptResolvingRequest(randomRequest.getDuration());
    std::cout << serverGroup[1].to_string();
}

void TestLoadBalancer::simulateLoadBalancer(int initRequestAmount, int initServerAmount, int clockCycles)
{
    RequestQueue requestQueue(initRequestAmount);
    LoadBalancer loadBalancer(initServerAmount);
    std::cout << loadBalancer.to_string() << std::endl;

    int nextCycleToGenerateRequest = rand() % 41 + 10;

    for(int i = 0; i < clockCycles; i++)
    {
        if (i >= nextCycleToGenerateRequest)
        {
            Request randomRequest = Request();
            requestQueue.push(randomRequest);
            nextCycleToGenerateRequest = rand() % 41 + 10 + i;
        }

        bool canKeepProcessingRequests = true;
        while (canKeepProcessingRequests)
        {
            bool requestToProcess = false;
            Request curReq;

            if (requestQueue.empty())
            {
                canKeepProcessingRequests = false;
            } else
            {
                curReq = requestQueue.front();
                requestToProcess = true;
            }

            if (requestToProcess)
            {
                if (loadBalancer.processNewRequestAndUpdateServerStates(&curReq, i))
                {
                    requestQueue.pop();
                } else
                {
                    canKeepProcessingRequests = false;
                }
            } else
            {
                loadBalancer.updateServerStates(i);
            }
        };
    }

    std::cout << "Still " << requestQueue.size() << " left in queue";

}