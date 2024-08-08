#include <iostream>
#include <alpha/element.h>
#include <logger.h>
#include <numeric>

electronic_configuration::electronic_configuration(const int charge){
    _charge = charge;

    //Просчет электронной конфигурации
    //0 - s, 1 - p, 2 - d, 3 - f



    int cash_charge{charge};
    int ostatok_before_end{charge};
    int period{1};

    _electronic_configuration = electronic_configuration::generate_configuration_stupid_method(&cash_charge);

}

electronic_configuration::operator std::string (){
    std::string out;
    std::vector<std::vector<int>>::iterator el_config_iterator;

    int n = 0;
    std::vector<int> current_orbit;
    int len;
    for(el_config_iterator = _electronic_configuration.begin(); el_config_iterator < _electronic_configuration.end(); el_config_iterator++){

        current_orbit = *el_config_iterator;

        len = std::accumulate(current_orbit.begin(), current_orbit.end(),0);

        switch (current_orbit.size())
        {
        case 1:
            if (len == 2) {n++;};
            out += std::to_string(n) + "S" + std::to_string(len) + " ";
            break;
        case 3:
            out += std::to_string(n) + "P" + std::to_string(len) + " ";
            break;
        case 5:
            out += std::to_string(n-1) + "D" + std::to_string(len) + " ";
            break;
        case 7:
            out += std::to_string(n-2) + "f" + std::to_string(len) + " ";
            break;
        default:
            break;
        }
    }

    return out;
}

element::element(const int charge): _electronic_configuration(charge) {

8   ; _charge = charge;   //??
    
}

electronic_configuration element::get_electronic_configuration() {
    return _electronic_configuration;
}



std::vector<std::vector<int>> electronic_configuration::generate_configuration_stupid_method(int *aviable_electrons){
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>{};

    int nal = 0;
    int cash{*aviable_electrons};

    while (cash > 0)
    {

        nal++;

        int n = 0;
        int l = 0; 
        for (n = 0; n <= nal; n++){
            l = nal - n;

            if (l >= n) {
                continue;
            }

            

            switch (l)
            {
            case 0:
                result.emplace_back(electronic_configuration::generate_orbit(ENERGY_LEVEL::S_LEVEL, &cash));
                break;
            case 1:
                result.emplace_back(electronic_configuration::generate_orbit(ENERGY_LEVEL::P_LEVEL, &cash));
                break;
            case 2:
                result.emplace_back(electronic_configuration::generate_orbit(ENERGY_LEVEL::D_LEVEL, &cash));
                break;
            case 3:
                result.emplace_back(electronic_configuration::generate_orbit(ENERGY_LEVEL::F_LEVEL, &cash));
                break;
            default:
                break;
            }
            
            if (cash <= 0) {
                break;
            }  
        }
        


        
    }
    
    return result;

}

std::vector<int> electronic_configuration::generate_orbit(electronic_configuration::ENERGY_LEVEL orbit_type, int *electrons){
    std::vector<int> result;
    bool by_two = false;
    float max_full_orbits = 0;

    logger::make_message("Создаю орбиталь. Остаток:" + std::to_string(*electrons) + "Тип: " + std::to_string(orbit_type) , MSG_TYPE::INFO);

    switch (orbit_type)
    {
    case ENERGY_LEVEL::S_LEVEL:
        if (*electrons >= 2) {
            result = std::vector<int>{2};
        } else {
            result = std::vector<int>{*electrons};
        }
        *electrons -= 2;
        return result;
        break;
    case ENERGY_LEVEL::P_LEVEL:
        if (*electrons >= 6) {
            result = std::vector<int>{2, 2, 2};
            *electrons -= 6;
            return result;
        } else {
            result = std::vector<int>{0,0,0};

            max_full_orbits = *electrons % 3;

            if (*electrons > 3) {
                by_two = true;
            }
        }
        break;
    case ENERGY_LEVEL::D_LEVEL:
        if (*electrons >= 10) {
            result = std::vector<int>{2, 2, 2, 2, 2};
            *electrons -= 10;
            return result;
        } else {
            result = std::vector<int>{0,0,0,0,0};

            max_full_orbits = *electrons % 5;

            if (*electrons > 5) {
                by_two = true;
            }
        }
        break;
    case ENERGY_LEVEL::F_LEVEL:
        if (*electrons >= 10) {
            result = std::vector<int>{2, 2, 2, 2, 2, 2, 2};
            *electrons -= 10;
            return result;
        } else {
            result = std::vector<int>{0, 0, 0, 0, 0, 0, 0};

            max_full_orbits = *electrons % 7;

            if (*electrons > 7) {
                by_two = true;
            }
        }
        break;
    default:
        break;
    }

    std::vector<int>::iterator result_iterator = result.begin();

    for (int i = 0; i < max_full_orbits; i++) {
        if (by_two) {
            *result_iterator = 2;
            *electrons -= 2;
        } else {
            *result_iterator = 1;
            *electrons -= 1;
        }
        result_iterator++;
    }

    while (*electrons > 0) {
        *result_iterator += 1;
        *electrons-=1;
        result_iterator++;
    }

    return result;    



}
