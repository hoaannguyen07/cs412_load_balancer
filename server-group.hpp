#include "server.hpp"

#include <vector>
#include <string>

#ifndef SERVERGROUP_HPP
#define SERVERGROUP_HPP

/**
 * @brief A grouping of servers with the same capabilities
 * 
 */
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

    /**
     * @brief Get the size of the server group
     * 
     * @return int 
     */
    int size();

    /**
     * @brief Get a summary of the server group
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif