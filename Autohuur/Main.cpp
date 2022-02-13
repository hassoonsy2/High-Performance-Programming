#include <iostream> 
#include "AutoHuur.hpp"
#include "Auto.hpp"
#include "Klant.hpp"

int main()
{
    Klant k("Mijnheer de Vries");
    k.set_korting_percentage(10.0);
    Auto a1("Peugeot 207", 50);
    AutoHuur ah1(a1, k, 4);
    std::cout << "Eerste autohuur:"<< ah1 <<endl;
    std::cout << endl;
    
    Auto a2("Ferrari", 3500);
    AutoHuur ah2(a1, k, 10);
    ah2.set_gehuurde_auto(a2);
    ah2.set_aantal_dagen(1);
    std::cout << "Tweede autohuur: "<< ah2 << endl;
    std::cout << endl;
    
    std::cout << "Gehuurd: " << ah1.get_gehuurde_auto()<< endl;
    std::cout << "Gehuurd: " << ah2.get_gehuurde_auto()<< endl;
    
    return 0;
};
