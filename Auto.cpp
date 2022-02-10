#include <iostream> 
#include "Auto.hpp"


Auto::Auto(std::string type , double prijs_per_dag){
    this -> type = type; 
    this -> prijs_per_dag = prijs_per_dag;

}; 

void Auto:: set_prijs_per_dag(double prijs_per_dag){
    this -> prijs_per_dag = prijs_per_dag; 
}; 

double Auto:: get_prijs_per_dag() const{
    return prijs_per_dag;
};

ostream& operator<<(ostream& os , const Auto& auto1){
    os <<" Auto :"<< auto1.type << "Prijs per dag is : " << auto1.prijs_per_dag<<endl;
};







