#pragma once

#include "Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "Persoon.hpp"

using std::ostream, std::endl , std::string;
using std::vector; using std::find;


Persoon::Persoon(std::string naam , double budget){
	this -> naam = naam; 
	this-> budget = budget;
}; 

string Persoon::get_naam() const {
	return naam;
};

void Persoon::set_budget(double budget) {
	budget = budget;
};

double Persoon::get_budget() const {
	return budget;
};

vector<Game> Persoon::getGames() const {
	return games;
}; 




static Persoon::koop(Game game){
	if(*find(games.begin(), games.end(), game)!= game && Persoon.get_budget() >= game.get_prijs_na_korting()) {
		games.push_back(game);

		std::cout << "Gelukt ";
	}

	else
	{
		std::cout << "Niet gelukt";
		
	}
};



static Persoon::verkoop(Game g, Persoon koper){

	if(*find(koper.games.begin(), koper.games.end(), g) != g && koop.budget >= g.get_prijs_na_korting()){
		koper.koop(g);
		games.erase(g);
		std::cout << "Gelukt ";
	}
	else{
		std::cout << "Niet gelukt ";
		

	}



};

ostream& operator<<(ostream& os , const Persoon& persoon){
os << persoon.get_naam() <<" heeft een budget van  "<< persoon.get_budget()<< "en bezit de volgende games:" <<persoon.getGames()<<endl;
};

