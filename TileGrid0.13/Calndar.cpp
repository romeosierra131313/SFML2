#include "include/Calndar.h"
#include <iostream>

namespace romeo{   
       
Calndar::Calndar(){
    std::cout<<"Calndar called"<<std::endl;
     
}



void Calndar::initi(romeo::Resource* rm,sf::RenderWindow* window){
     currentMonth = 0;
     currentDate = 1;
    
    
     Month.setFont(*rm->getFont());
     Month.setString("Month--");
     Month.setCharacterSize(15);
     Month.setFillColor(sf::Color::White);
     Month.setPosition(480,0);
     
     Date.setFont(*rm->getFont());
     Date.setString("Date");
     Date.setCharacterSize(15);
     Date.setFillColor(sf::Color::White);
     Date.setPosition(544,0);
    
}


void Calndar::handleKeys(sf::Event e){
  
                    
}
void Calndar::changeMonth(int newMonth){
     currentMonth = newMonth;
     Month.setString(monthName[newMonth]);
    
}
void Calndar::changeDay(int newdate){
    std::string g = std::to_string(newdate);
    Date.setString(g);}

 void Calndar::update() {
         if(currentDate < monthLength[currentMonth]) {
       currentDate++;
       changeDay(currentDate);}
        else{
           currentDate = 0; 
           currentMonth++;
        }
       
        if(currentMonth<12){
            changeMonth(currentMonth);
            
        }else{ currentMonth = 0; }
     
}
void Calndar::render(sf::RenderWindow* mywindow,float t){ 
    
    

    
    
          mywindow->draw(Month);
          mywindow->draw(Date);

   }

;
}
  
