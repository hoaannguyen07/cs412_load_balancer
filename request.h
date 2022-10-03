#include <iostream>
#include <string.h>

#ifndef REQUEST_H
#define REQUEST_H

struct Request
{
    std::string ip_in;
    std::string ip_out;
    int duration;
};

Request generate_request();

#endif // REQUEST_H

