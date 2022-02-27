#include <iostream>
#include "Autohuur.hpp"
#include "Auto.hpp"
#include "Klant.hpp"

AutoHuur::AutoHuur(Auto auto1, Klant huurder, int aantal_dagen ){
    this -> auto1 = auto1; 
    this -> huurder = Klant; 
    this -> aantal_dagen = aantal_dagen; 

};

void AutoHuur::set_aantal_dagen(int aantal_dagen){
    this -> aantal_dagen = aantal_dagen; 

}; 

void AutoHuur::set_gehuurde_auto(Auto auto1){
    this -> auto1 = auto1;
}; 

Auto AutoHuur::get_gehuurde_auto() const{
    return auto1;
};

void AutoHuur::set_huurder(Klant huurder){
    this-> huurder = huurder;
     };

Klant AutoHuur::get_huurder() const{
    return huurder; 

}; 

double AutoHuur::totaalprijs(){

    double totaal_prijs_dagen = auto1.get_prijs_per_dag() * aantal_dagen; 
    double korting = (totaal_prijs_dagen - huurder.get_korting()) / 100 ;
    double totaal = totaal_prijs_dagen - korting; 
    return totaal;  

};

ostream& operator<<(ostream& os , const AutoHuur& autohuur){
    os <<" Auto : "<< autohuur.get_gehuurde_auto() << " , Naam van de klant   " << autohuur.get_huurder()<< " , totaal prijs :  "<< autohuur.totaalprijs()<< endl;
};
