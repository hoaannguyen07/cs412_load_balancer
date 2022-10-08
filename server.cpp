#include "server.hpp"

#include <string>

Server::Server(std::string serverName) : name(serverName)
{
    this->resetServer();
}

Server::~Server()
{
    this->resetServer();
}

bool Server::isAvailable()
{
    return this->m_requestCurrentlyHandling == nullptr;
}


void Server::assignRequest(Request* request, int curTime)
{
    this->resetServer(); // ensure that previous Requests have been properly deallocated

    this->m_requestCurrentlyHandling = new Request(*request);
    this->m_requestStartTime = curTime;
    this->m_requestEndTime = curTime + request->getDuration();
}

bool Server::isReadyToResolveRequest(int curTime)
{
    return curTime >= this->m_requestEndTime;
}

void Server::attemptResolvingRequest(int curTime)
{
    if (this->isAvailable())
    {
        std::cout << "Server is currently not processing any requests";
        return;
    }
    
    if (!this->isReadyToResolveRequest(curTime))
    {
        // std::cout << "Can't Resolve just yet";
        return;
    }

    std::string output;
    output += "\n===========================================================================\n";
    output += "Server [" + this->name + "] Request Resolution Summary:\n";
    output += "Start Time: " + std::to_string(this->m_requestStartTime) + '\n';
    output += "End time: " + std::to_string(curTime) + '\n';
    output += this->m_requestCurrentlyHandling->to_string();
    output += "===========================================================================\n";
    
    std::cout << output;

    this->resetServer();
}

void Server::resetServer()
{
    if (this->m_requestCurrentlyHandling != nullptr)
    {
        delete this->m_requestCurrentlyHandling;
        this->m_requestCurrentlyHandling = nullptr;
    }
    this->m_requestStartTime = -1;
    this->m_requestEndTime = -1;
}

std::string Server::to_string()
{
    std::string serverAvailability = (this->isAvailable()) ? "Available" : "Unavailable";
    std::string result = "Server [" + this->name + "] is currently " + serverAvailability + '\n';

    return result;
}