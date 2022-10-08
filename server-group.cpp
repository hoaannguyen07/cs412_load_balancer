#include "server-group.hpp"


ServerGroup::ServerGroup(int size)
{
    this->m_serverArray = std::vector<Server>();
    for(int i = 0; i < size; i++)
    {
        char letter = 'A' + i;
        std::string serverName;
        serverName += letter;
        Server server = Server(serverName);
        this->m_serverArray.push_back(server);
    }
}

Server& ServerGroup::operator[](int index)
{
    return this->m_serverArray[index];
}

int ServerGroup::size()
{
    return this->m_serverArray.size();
}

std::string ServerGroup::to_string()
{
    std::string result;
    
    result += "\n===========================================================================\n";
    result += "Server Group\n";
    result += "Group Size: " + std::to_string(this->size()) + '\n';
    result += "---------------------------------------------------------------------------\n";
    result += "[\n";

    for(int i = 0 ; i < this->size(); i++)
    {
        Server curServer = this->operator[](i);
        result += '\t' + curServer.to_string();
    }
    result += "]\n";
    result += "===========================================================================\n";

    return result;
}