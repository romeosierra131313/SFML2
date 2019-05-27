 
 
#ifndef BATTLEMENU_H
#define BATTLEMENU_H
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

namespace mine{
    
class battlemenu{
    
   public:
       int x = 0;
       int y = 0;
       int width;
       int height ;
       
       
        bool active;
        int position;
        sf::Vector2i location;
        sf::RectangleShape back;
        sf::Font font;
        sf::Text moveT;
        sf::Text attackT;
        sf::Text skillsT;
        sf::Text itemsT;
        sf::Text fleeT;
        


        
       battlemenu();
       ~battlemenu(){}
        void  setup(sf::Vector2i loca,int wWidth,int wHeight,sf::Font fnt);
        void handleInput(sf::Event Event);
        void  setActive(bool b);
        bool  getActive();
        

      battlemenu(const battlemenu&) = delete;
      battlemenu& operator=(const battlemenu&) = delete;
      

      
};
}

#endif
