#include <iostream>
#include"Auto.hpp"
#include"Klant.hpp"
#pragma once

using std::ostream, std::endl;

class AutoHuur{
    private: 
        Auto auto1; 
        Klant huurder;
        int aantal_dagen;


    public: 
    AutoHuur(Auto auto1, Klant huurder, int aantal_dagen);
    void set_aantal_dagen(int aantal_dagen);
    void set_gehuurde_auto(Auto auto1);
    Auto get_gehuurde_auto() const;
    void set_huurder(Klant huurder);
    Klant get_huurder() const;
    double totaalprijs() const;
    friend ostream& operator<<(ostream& os,const AutoHuur& autohuur);

};