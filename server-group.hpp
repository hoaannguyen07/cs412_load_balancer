
#ifndef SERVERGROUP_HPP
#define SERVERGROUP_HPP

#include "server.hpp"

#include <vector>
#include <string>

/**
 * @brief Class modeling a group of servers with the same capabilities/specs
 * 
 */
class ServerGroup
{
private:
    std::vector<Server> m_serverArray;
public:
    /**
     * @brief Construct a new Server Group object with no servers to start out with
     * 
     */
    ServerGroup();
    
    /**
     * @brief Construct a new Server Group object with an initial number of servers
     * 
     * @param size Initial number of servers the server group will have
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
     * @brief Get a summary of the server group in string format
     * 
     * @return std::string 
     */
    std::string to_string();
};

#endif