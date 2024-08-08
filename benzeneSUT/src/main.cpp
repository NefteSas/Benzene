#include <alpha/element.h>
#include <logger.h>
#include <iostream>

int main(){

    int n;

    std::cin >> n;

    element foo = element(n);

    logger::make_message(foo.get_electronic_configuration(), MSG_TYPE::INFO);

    return 0;
}