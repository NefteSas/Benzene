#include <alpha/element.h>
#include <logger.h>
#include <iostream>

int main(){
    int start = 10;
    while (true) {
        std::cin >> start;
        element foo = element(start);
        logger::make_message(electronic_configuration::to_string(foo.get_electronic_configuration().get_orbits()), MSG_TYPE::INFO);
    }
        

    return 0;
}