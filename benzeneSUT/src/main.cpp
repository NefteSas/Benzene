#include <alpha/element.h>
#include <logger.h>
#include <iostream>

int main(){
    std::cout << "Gen from ";
    int a;
    int b;
    std::cin >> a;
    std::cout << "To ";
    std::cin >> b;

    element foo = element(a);
    for (int i = a + a; i < b; i++) {
        foo = element(i);
        logger::make_message(foo.get_electronic_configuration(), MSG_TYPE::INFO);
    }
    
    
    int k;
    std::cin >> k;
    return 0;
}