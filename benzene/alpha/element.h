#pragma once
#include <vector>
#include <string>
class electronic_configuration
{



    private:
        int _charge;

        //0 - s, 1 - p, 2 - d, 3 - f
        std::vector<std::vector<int>> _electronic_configuration; //Последний энергетический уровень последовательность следующая: 0 - s; 1 - p; 2 - s`; 3 - d;
    public:
        enum ENERGY_LEVEL{
            S_LEVEL,
            P_LEVEL,
            D_LEVEL,
            F_LEVEL
        };

        
        
        electronic_configuration(const int charge);
        std::vector<std::vector<int>> return_last_orbit();

        std::vector<std::vector<int>> get_orbits();

        static std::vector<std::vector<int>> generate_configuration_stupid_method(int aviable_electrons);
        
        static std::string to_string(std::vector<std::vector<int>> orbit);

        static std::vector<int> generate_orbit(electronic_configuration::ENERGY_LEVEL orbit_type, int *electrons);

        operator std::string();
        //де факто нас интересует только последняя орбиталь

        
};

class element
{
private:
    int _charge;
    electronic_configuration _electronic_configuration;
public:
    element(const int charge);    
    electronic_configuration get_electronic_configuration();
};



