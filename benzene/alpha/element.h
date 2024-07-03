#pragma once

class electronic_configuration
{
    private:
        int _charge;
        int *pointer_to_array = nullptr;
    public:
        electronic_configuration(const int charge);

        

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



