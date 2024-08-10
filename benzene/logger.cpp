#include <logger.h>

void logger::make_message(std::string msg, MSG_TYPE msg_type){
    switch (msg_type)
    {
    case MSG_TYPE::INFO:
        std::cout << "\r[INFO] " << msg << "  " << std::endl;
        break;
    
    default:
        break;
    }
}

void logger::make_continous_message(std::string msg, MSG_TYPE msg_type){
    switch (msg_type)
    {
    case MSG_TYPE::INFO:
        std::cout << "\r[INFO] " << msg << "  " << std::flush;
        break;
    
    default:
        break;
    }
}