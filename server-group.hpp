#include "server.hpp"

#include <vector>
#include <string>

#ifndef SERVERGROUP_HPP
#define SERVERGROUP_HPP

class ServerGroup
{
private:
    std::vector<Server> m_serverArray;
public:
    /**
     * @brief Construct a new Server Group object with an initial number of servers
     * 
     * @param size 
     */
    ServerGroup(int size);
    ~ServerGroup() {};

    /**
     * @brief Get server at a certain index in the server group
     * 
     * @param index Index of wanted server in the server group
     * @return Server 
     */
    Server& operator[] (int index);
    int size();

    std::string to_string();
};

#endif