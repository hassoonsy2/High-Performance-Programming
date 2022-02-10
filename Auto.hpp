#include <iostream>

class Auto{

    private: 
        std::string type; 
        double prijs_per_dag;
    
    public: 

    Auto(std::string type , double prijs_per_dag); 

    void set_prijs_per_dag(double prijs_per_dag); 

    double get_prijs_per_dag(); 

    
};