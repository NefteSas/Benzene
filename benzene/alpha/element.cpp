#include <iostream>
#include <element.h>

electronic_configuration::electronic_configuration(const int charge){
    _charge = charge;

    //Просчет электронной конфигурации
    //0 - s, 1 - p, 2 - d, 3 - f

    int current_energy_level = 0;
    int i{charge};
    while(i > 0){

        //срезаем кол-во итераций
        
        if (current_energy_level == 0 & i > 2)  {
            //Срезаем из цикла первые элементы H, Li
            i-=2;
            current_energy_level +=1; //Переходим на p период
            continue;
        }
        if (1 <= current_energy_level <= 2 & i> 8) { //Если мы на p периоде и остаток > 8, тогда перескок
            i-=8;
            current_energy_level+=1;
            continue;
        }
        if (3 <= current_energy_level <= 5 & i> 18) { //Если мы на d периоде и остаток > 18, тогда перескок
            i-=18;
            current_energy_level+=1;
            continue;
        }
        if (5 < current_energy_level & i > 32) { //ОСТАВЬ НАДЕЖДУ, ВСЯК НА f УРОВЕНЬ ВХОДЯЩИЙ
            i-=32;
            current_energy_level+=1;
            continue;
        }

    }
    
}

element::element(const int charge): _electronic_configuration(charge) {

    _charge = charge;    
    
}

electronic_configuration element::get_electronic_configuration() {
    return _electronic_configuration;
}
