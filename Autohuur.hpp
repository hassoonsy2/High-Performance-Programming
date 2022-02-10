#include <iostream> 

class AutoHuur{
    private: 
        int aantal_dagen;
        Auto auto; 
        Klant huurder; 


    public: 
    AutoHuur(auto :Auto , huurder: Klant, dagen : int );
    void set_aantal_dagen(d: int);
    void set_gehuurde_auto(auto: Auto);
    Auto get_gehuurde_auto();
    void set_huurder(huurder : Klant);
    Klant get_huurder();
    double totaalprijs();
};