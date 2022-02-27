
#pragma once
#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <ctime> 
#include <algorithm>  
using std::ostream, std::endl , std::string;
using std::vector; using std::find;


Game::Game(string naam , int releasejaar , double prijs){
    this-> naam = naam; 
    this-> releasejaar = releasejaar; 
    this -> prijs = prijs; 
};

double Game::get_prijs_na_korting() const {
    time_t curr_time = time(NULL);
    tm *tm_local = localtime(&curr_time);
    int currentYear = tm_local->tm_year + 1900;

    double new_prijs = this->prijs;
    for (int i = 0; i < (currentYear - this->releasejaar); i++) {
        new_prijs *= 0.7;
    };

    return new_prijs;  
};

double Game::get_prijs() const{
    return prijs;
};


int Game::get_releasejaar() const{
    return releasejaar;
};

string Game::get_naam() const{
    return naam;
};


ostream& operator<<(ostream& os , const Game& game){
os << game.get_naam() <<", uitgegeven in "<< game.get_releasejaar()<< "; nieuwprijs:" << game.get_prijs()<< " nu voor:  "<< game.get_prijs_na_korting()<< endl;
};


