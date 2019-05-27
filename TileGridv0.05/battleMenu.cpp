#include <SFML/Graphics.hpp>
#include "battleMenu.h"
#include <iostream>

namespace mine{
  battlemenu::battlemenu(){  
      active = false;
    };     
    
    void battlemenu::setup(sf::Vector2i loca,int wWidth,int wHeight,sf::Font fnt){
        
        location = loca;
        font = fnt;
        
        sf::Color color(255, 0, 0,100); // red
        back.setSize(sf::Vector2f(wWidth,wHeight/2));
        back.setPosition(location.x,location.y);
        back.setFillColor(color);
        
        moveT.setFont(font); 
        moveT.setString("Move");
        moveT.setCharacterSize(24); // in pixels, not points!
        moveT.setFillColor(sf::Color::Red);
        moveT.setStyle(sf::Text::Bold | sf::Text::Underlined);
        moveT.setPosition(wWidth-(wWidth/4),(wHeight/20)*10);
        
        attackT.setFont(font); 
        attackT.setString("Attack");
        attackT.setCharacterSize(24); // in pixels, not points!
        attackT.setFillColor(sf::Color::Red);
        attackT.setStyle(sf::Text::Bold | sf::Text::Underlined);
        attackT.setPosition(wWidth-(wWidth/4),(wHeight/20)*11);
         
        skillsT.setFont(font); 
        skillsT.setString("Skills");
        skillsT.setCharacterSize(24); // in pixels, not points!
        skillsT.setFillColor(sf::Color::Red);
        skillsT.setStyle(sf::Text::Bold | sf::Text::Underlined);
        skillsT.setPosition(wWidth-(wWidth/4),(wHeight/20)*12);    
        
        itemsT.setFont(font); 
        itemsT.setString("itemsT");
        itemsT.setCharacterSize(24); // in pixels, not points!
        itemsT.setFillColor(sf::Color::Red);
        itemsT.setStyle(sf::Text::Bold | sf::Text::Underlined);
        itemsT.setPosition(wWidth-(wWidth/4),(wHeight/20)*13);
        
        fleeT.setFont(font); 
        fleeT.setString("fleeTT");
        fleeT.setCharacterSize(24); // in pixels, not points!
        fleeT.setFillColor(sf::Color::Red);
        fleeT.setStyle(sf::Text::Bold | sf::Text::Underlined);
        fleeT.setPosition(wWidth-(wWidth/4),(wHeight/20)*14);
        
//         sf::Text skillsT;
//         sf::Text itemsT;
//         sf::Text fleeT;
             
    }
    void battlemenu::handleInput(sf::Event Event){
        if(active){
            
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::X)){
                
                setActive(false);
            }
                         if(Event.key.code == sf::Keyboard::Up){ 
                  position -= 1;
                  
            }
              if(Event.key.code == sf::Keyboard::Down){ 
                  position += 1;
                  
            }
              if(Event.key.code == sf::Keyboard::Z){ 
                  
                  
            }
            
            
            
        }
        
    }
    void  battlemenu::setActive(bool b){
        std::cout << b << std::endl;
        active = b;
        
    }
    bool  battlemenu::getActive(){
          
        return active;
        
    }

}
 
