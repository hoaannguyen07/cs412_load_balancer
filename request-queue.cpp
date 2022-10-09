#include "request-queue.hpp"

RequestQueue::RequestQueue(int initRequestAmount = 500)
{
    this->m_initQueueSize = initRequestAmount;
    this->m_requestQueue = std::queue<Request>();

    for(int i = 0; i < initRequestAmount; i++)
    {
        // Request randomRequest = Request();
        this->m_requestQueue.push(Request());
    }
}

Request RequestQueue::getNextRequest()
{
    Request nextRequest = this->front();
    this->pop();
    return nextRequest;
}

Request RequestQueue::front()
{
    return this->m_requestQueue.front();
}

void RequestQueue::pop()
{
    this->m_requestQueue.pop();
}

void RequestQueue::push(Request& newRequest)
{
    this->m_requestQueue.push(newRequest);
}

bool RequestQueue::empty()
{
    return this->m_requestQueue.empty();
}

int RequestQueue::size()
{
    return this->m_requestQueue.size();
}

std::string RequestQueue::to_string()
{
    std::string result;

    result += "\n===========================================================================\n";
    result += "Request Queue\n";
    result += "Initial Queue Size: " + std::to_string(this->m_initQueueSize) + '\n';
    result += "Current Queue Size: " + std::to_string(this->m_requestQueue.size()) + '\n';
    result += "---------------------------------------------------------------------------\n";

    while(!this->m_requestQueue.empty())
    {
        result += "Queue Size: " + std::to_string(this->m_requestQueue.size()) + '\n';
        Request curRequest = this->getNextRequest();
        result += curRequest.to_string();
    }

    result += "Queue Size: " + std::to_string(this->m_requestQueue.size()) + '\n';

    result += "QUEUE IS NOW EMPTY BECAUSE ALL REQUESTS HAS BEEN POPPED";
    result += "\n===========================================================================\n";

    return result;
}