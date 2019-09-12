#include "include/Resource.h"
#include "include/Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>


 
sf::RenderWindow window(sf::VideoMode(1440,1280), "SFML works!");
sf::View gui_view(sf::FloatRect(360,200, 720, 480));
sf::View map_view(sf::FloatRect(360,200, 1440, 1280));
romeo::Game game;


void doSetup(){
 window.setFramerateLimit(30);
game.setWindow(&window,&gui_view,&map_view);
game.rm.addView(&gui_view,&map_view );


}

void handleKeys(sf::Event e){
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)){//////escape!!//////
              window.close();
            }
    
    
}

void Loop(){
       sf::Clock clock; 
      
      while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
                handleKeys(event);//////////main 
                game.handleKeys(event);////game
        
            
        }


       window.clear(sf::Color::Black); 
        
       sf::Time t = clock.getElapsedTime() ;
       game.render(&window,t.asMilliseconds());
        
        window.display();
      

        
        
    }
}
int main(){
    std::cout<<"initialized main" << std::endl;
    doSetup(); 
    std::cout<<"starting main loop" << std::endl;
    Loop();



    return 0;
}
