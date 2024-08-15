#include <iostream>
#include <alpha/element.h>
#include <logger.h>
#include <cmath>
#include <numeric>

electronic_configuration::electronic_configuration(const int charge){
    _charge = charge;

    //Просчет электронной конфигурации
    //0 - s, 1 - p, 2 - d, 3 - f



    int cash_charge{charge};
    int ostatok_before_end{charge};
    int period{1};

    logger::make_message("Element generation process has started. Charge number: " + std::to_string(charge), MSG_TYPE::INFO);
    _electronic_configuration = electronic_configuration::generate_configuration_stupid_method(cash_charge);

}

electronic_configuration::operator std::string (){

    return to_string(_electronic_configuration);

}

std::string electronic_configuration::to_string(std::vector<std::vector<int>> orbit) { 
    std::string out;
    std::vector<std::vector<int>>::iterator el_config_iterator;

    int n = 0;
    std::vector<int> current_orbit;
    int len;

    for(el_config_iterator = orbit.begin(); el_config_iterator < orbit.end(); el_config_iterator++){

        current_orbit = *el_config_iterator;

        len = std::accumulate(current_orbit.begin(), current_orbit.end(),0);

        switch (current_orbit.size())
        {
        case 1:
            n++;
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

};

element::element(const int charge): _electronic_configuration(charge) {

8   ; _charge = charge;   //??
    
}

electronic_configuration element::get_electronic_configuration() {
    return _electronic_configuration;
}

std::vector<std::vector<int>> electronic_configuration::get_orbits() {

    return _electronic_configuration;

}


std::vector<std::vector<int>> electronic_configuration::generate_configuration_stupid_method(int aviable_electrons){
    std::vector<std::vector<int>> result = std::vector<std::vector<int>>{};
    std::vector<std::vector<int>>::iterator last_s_iterator;

    int nal = 0;
    int cash = aviable_electrons;
    
    while (cash > 0)
    {

        logger::make_message("Generating element with charge " + std::to_string(aviable_electrons) + " | " + std::to_string((1 - (float(cash) / float(aviable_electrons))) * 100) + "%", MSG_TYPE::INFO);

        nal++;

        int n = 0;
        int l = 0; 
        for (n = 0; n <= nal; n++){
            l = nal - n;

            

            if (l >= n) {
                continue;
            }
            
            float k = 100 - std::round((float(cash) / float(aviable_electrons) * 100.0));

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
    
    //теперь фильтруем
    int len;
    std::vector<std::vector<int>>::iterator orbit_buffer;
    std::vector<std::vector<int>>::iterator orbit_buffer_neded_iter;
    for(std::vector<std::vector<int>>::iterator i = result.begin(); i < result.end(); i++) {

        if ((*i).size() == 1) {
            last_s_iterator = i;
        }

    }

    for (std::vector<std::vector<int>>::iterator i = last_s_iterator; i < result.end(); i++ ) {
        if ((*i).size() == 5) {
            orbit_buffer = i;

            len = std::accumulate((*orbit_buffer).begin(), (*orbit_buffer).end(), 0);


            if (len < (*orbit_buffer).size()) {
                (*orbit_buffer)[len]++;
            } else if ((*orbit_buffer).size() < len < ((*orbit_buffer).size() * 2))
            {   
                if ((len + (*last_s_iterator).front()) == ((*orbit_buffer).size() * 2)) { 

                    (*orbit_buffer) = std::vector<int>((*orbit_buffer).size(), 2);
                    (*last_s_iterator).front() = 0;
                    break;
                 }
                (*orbit_buffer)[(len-5)]++;
            }
        
            (*last_s_iterator).front()--;
        }
    }

    logger::make_message("Gen ended", MSG_TYPE::INFO);


    return result;

}

std::vector<std::vector<int>> electronic_configuration::return_last_orbit() {
    
    std::vector<std::vector<int>> last_orbit;
    std::vector<std::vector<int>>::iterator last_s_pos;

    bool reversed = false;

    for (auto i = _electronic_configuration.begin(); i <= _electronic_configuration.end(); i++)   {
        
        if (( ( (std::vector<int>)(*i) ).size() == 1 )) {

            last_s_pos = i;

        }

    }

    for (auto i = last_s_pos; i < _electronic_configuration.end(); i++)   {
       
        last_orbit.emplace_back(*i);

    }

    return last_orbit;
    

}

std::vector<int> electronic_configuration::generate_orbit(electronic_configuration::ENERGY_LEVEL orbit_type, int *electrons){
    std::vector<int> result;
    float start_el = (float)*electrons;
    bool by_two = false;
    float max_full_orbits = 0;

    std::cout << *electrons;

    switch (orbit_type)
    {
    case ENERGY_LEVEL::S_LEVEL:
        if (*electrons >= 2) {
            result = std::vector<int>{2};
        } else {
            result = std::vector<int>{1};

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
        if (*electrons >= 14) {
            result = std::vector<int>{2, 2, 2, 2, 2, 2, 2};
            *electrons -= 14;
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
