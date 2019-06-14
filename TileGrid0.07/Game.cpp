#include "Game.h"
#include "Resource.h"
#include <iostream>

namespace romeo{
romeo::screena a(64,16,16);
         
Game::Game(){
        int Tilewidth=64;
        
        std::cout<<"Game start" << std::endl;
        std::cout<<"set screen" << std::endl;
        Resource_Manager.Cut_Image(Resource_Manager.return_Image("assets/terra.png"),Tilewidth );
        std::cout<<"loading and cutting tiles" << std::endl;
        
        a.nit(&Resource_Manager);
        setScreen(&a);

}
void Game::setScreen(romeo::screen* current_screen ){
        screen = current_screen;
}
void Game::handleKeys(sf::Event e,sf::View* v,sf::RenderWindow* rw){
    
            screen->handleKeys(e);
            Resource_Manager.handleKeys(e);
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)){//////escape!!//////
              
                std::cout<<"Escaping";
            }
            
            
            ////////////////////////////////////////// 
            //////////////MOVE MAP AROUND/////////////
            ////////////////////////////////////////// 
                newCenter =v->getCenter();
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::W)){//////escape!!//////
                
                
                newCenter.y -= 10;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::S)){//////escape!!//////
                
                newCenter.y += 10;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::A)){//////escape!!//////
                
                newCenter.x -= 10;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::D)){//////escape!!//////
                
                newCenter.x += 10;
                
            }
            
            v->setCenter(newCenter);
            rw->setView(*v);
            ////////////////////////////////////////// 
            //////////////MOVE MAP AROUND/////////////
            ////////////////////////////////////////// 
            
    
}

void Game::render(sf::RenderWindow* mywindow,float t){
          screen->render(mywindow,t);
    
}
;
}

