#include <iostream>
#include "element.h"



element::element(const char id[], const __int8 charge) {
    memcpy(_id, id, MAX_ELEMENT_LENGH*sizeof(char));
    
    _charge = charge;
    
    __int8 aviable_electrons = charge;

    //Просчет электронной конфигурации
    //0 - s, 1 - p, 2 - d, 3 - f
    while (aviable_electrons!=0)
    {

        aviable_electrons-=1; //К концу цикла вычитаем элекртон
    }
    
}

char *element::get_char_id() {
    return _id;
}