#include <iostream>
#pragma once
enum MSG_TYPE {
    WARN,
    INFO
};

class logger
{
private:
    /* data */
public:
    logger(/* args */);
    static void make_message(std::string msg, MSG_TYPE msg_type);
    static void make_continous_message(std::string msg, MSG_TYPE msg_type);
    ~logger();
};