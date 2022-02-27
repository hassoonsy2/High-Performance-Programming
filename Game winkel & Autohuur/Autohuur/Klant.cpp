#include <iostream> 
#include "Klant.hpp"

Klant::Klant(std::string naam){
    this->naam = naam;
    };

void Klant::set_korting_percentage(double korting_percentage){
        this->korting_percentage = korting_percentage;
    };

double Klant::get_korting() const{
    return korting_percentage;
};

ostream& operator<<(ostream& os , const Klant& klant){
    os <<" Klant naam :"<< klant.naam << "Met korting van : " << klant.get_korting()<<endl;
};



