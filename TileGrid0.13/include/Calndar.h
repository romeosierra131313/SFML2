  
#ifndef CALNDAR_H
#define CALNDAR_H

#include <string>
#include "include/Resource.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
class Calndar{
    private:
        bool hasFocus;
        sf::Text Month;
        sf::Text Date;

        
        
        
    public:
                int currentMonth;
        int currentDate;
    int monthLength[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    std::string monthName[13] = {"Jan","Feb","Mar","Apr",
                            "May","Jun","Juul",
                            "Aug","Sep","Oct","Nov","Dec"} ;
        
    Calndar();
    void initi(romeo::Resource*,sf::RenderWindow*);
    void changeMonth(int);
    void changeDay(int);
    void update();
    
    
    
    void handleKeys(sf::Event e);
    void render(sf::RenderWindow* mywindow,float);  
    
};
}
#endif
