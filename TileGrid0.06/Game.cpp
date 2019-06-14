#include "Game.h"
#include "Resource.h"
#include <iostream>

namespace romeo{
         romeo::screena a(64,32,32);
         romeo::Resource resource_manager;
         
Game::Game(){
            
        std::cout<<"Game start" << std::endl;
        std::cout<<"set menu screen" << std::endl;
        a.nit(resource_manager);
        setScreen(&a);

}
void Game::setScreen(romeo::screen* current_screen ){
    
    screen = current_screen;
}
void Game::handleKeys(sf::Event e){
            screen->handleKeys(e);
            resource_manager.handleKeys(e);
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)){//////escape!!//////
              
                std::cout<<"Escaping";
            }
    
    
}

void Game::render(sf::RenderWindow* mywindow,float t){
          screen->render(mywindow,t);
    
}
;
}

