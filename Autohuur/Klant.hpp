#include <iostream>
#pragma once

using std::ostream, std::endl;

class Klant{
    private: 
        std::string naam;
        double korting_percentage;

    public: 
    void set_korting_percentage(double korting_percentage);
    Klant(std::string naam);
    double get_korting() const;
    friend ostream& operator<<(ostream& os,const Klant& klant);

}; 