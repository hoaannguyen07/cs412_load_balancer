#include "request.hpp"

#include <string>

#ifndef SERVER_HPP
#define SERVER_HPP

class Server
{
private:
    std::string name;
    Request* m_requestCurrentlyHandling = nullptr;
    int m_requestStartTime = -1;
    int m_requestEndTime = -1;

    bool isReadyToResolveRequest(int);
public:
    Server(std::string);
    ~Server();

    bool isAvailable();
    void assignRequest(Request*, int);
    void attemptResolvingRequest(int);
    void resetServer();

    std::string to_string();
};

#endif // SERVER_HPP