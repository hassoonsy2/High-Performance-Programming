#include <iostream>
#include "Autohuur.hpp"

AutoHuur::AutoHuur(auto :Auto , huurder: Klant, dagen : int ){
    this -> auto = auto; 
    this -> huurder = huurder; 
    this -> dagen = dagen; 

};

void AutoHuur::set_aantal_dagen(d: int){
    this -> aantal_dagen = d; 

}; 

void AutoHuur::set_gehuurde_auto(auto: Auto){
    this -> auto = auto;
}; 

Auto AutoHuur::get_gehuurde_auto(){
    return auto;
};

void AutoHuur::set_huurder(huurder : Klant){
    this-> huurder = huurder;    };

Klant AutoHuur::get_huurder(){
    return huurder; 

}; 

double AutoHuur::totaalprijs(){

    double totaal_prijs_dagen =  auto.get_prijs_per_dag() * aantal_dagen; 
    double korting = (totaal_prijs_dagen - huurder.get_korting ) / 100 ;
    double totaal = totaal_prijs_dagen - korting; 
    return totaal;  

}