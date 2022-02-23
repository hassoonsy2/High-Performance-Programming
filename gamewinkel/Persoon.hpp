#pragma once

#include"Game.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>  

using std::ostream, std::endl , std::string;
using std::vector; using std::find;

class Persoon{
	private: 
		string naam;
		double budget;
		vector <Game> games;

	public:
	Persoon(string naam , double budget);

	string get_naam()const;

	void set_budget(double b);

	double get_budget()const;

	vector<Game> getGames()const;

	void set_game(Game g);


	void koop(Game game);

	void verkoop(Game g, Persoon koper);

	friend ostream& operator<<(ostream& os,const Persoon& persoon);
};

	 



	 
	

	
