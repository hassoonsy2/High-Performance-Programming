#include <iostream>
#pragma once

using std::ostream, std::endl;

class Auto{

    private: 
        std::string type; 
        double prijs_per_dag;
    
    public: 

    Auto(std::string type , double prijs_per_dag); 

    void set_prijs_per_dag(double prijs_per_dag); 

    double get_prijs_per_dag() const;

    friend ostream& operator<<(ostream& os,const Auto& auto1);

    
};