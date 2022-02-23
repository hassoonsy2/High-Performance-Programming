#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm> 
using std::ostream, std::endl , std::string;
using std::vector; using std::find;

class Game{
	private:
		string naam;
		double prijs ; 
		int releasejaar;

	public:
	Game(string naam , int releasejaar , double prijs);

	double get_prijs_na_korting() const;

	double get_prijs() const;

	int get_releasejaar() const;

	string get_naam() const;


	friend ostream& operator<<(ostream& os,const Game& game);

};

