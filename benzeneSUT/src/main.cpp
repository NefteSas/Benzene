#include <alpha/element.h>
#include <logger.h>
#include <iostream>

int main(){
    int start = 10;
    int end = 30;
    srand(time(0));
    int x = rand() % (end - start + 1) + start;
    
    element foo = element(103);

    
    
    logger::make_message(electronic_configuration::to_string(foo.get_electronic_configuration().get_orbits()), MSG_TYPE::INFO);

    return 0;
}