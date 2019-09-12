#include "include/Game.h"
#include <iostream>

namespace romeo{

       
Game::Game(){
        
        a.initi(Tilewidth,32,32,&rm);
        std::cout<<"Game start" << std::endl;
        std::cout<<"set screen" << std::endl;
        setScreen(&a);

}
void Game::setWindow(sf::RenderWindow* window,sf::View* gui_v,sf::View* map_v){
    mywindow = window;
    gui_view = gui_v;
        gui_view->reset(sf::FloatRect(0,0, 720, 480));
    map_view = map_v;
        map_view->reset(sf::FloatRect(360,200, 1440, 1280));
    a.setWindow(mywindow,gui_view,map_view);    
    
}
void Game::setScreen(romeo::screen* current_screen ){
        screen = current_screen;
}
void Game::handleKeys(sf::Event e){
    

            screen->handleKeys(e);
            rm.handleKeys(e);

            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::Escape)){//////escape!!//////
              
                std::cout<<"Escaping";
            }
            
            
            ////////////////////////////////////////// 
            //////////////MOVE MAP AROUND/////////////
            ////////////////////////////////////////// 
                newCenter =map_view->getCenter();
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::W)){//////escape!!//////
                
                mywindow->setView(*gui_view);
                newCenter.y -= 64;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::S)){//////escape!!//////
                mywindow->setView(*map_view);
                newCenter.y += 64;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::A)){//////escape!!//////
                
                newCenter.x -= 64;
                
            }
            if ((e.type == sf::Event::KeyPressed) && (e.key.code == sf::Keyboard::D)){//////escape!!//////
                
                newCenter.x += 64;
                
            }
            
            map_view->setCenter(newCenter);
            mywindow->setView(*map_view);
            ////////////////////////////////////////// 
            //////////////MOVE MAP AROUND/////////////
            ////////////////////////////////////////// 
            if (e.type == sf::Event::MouseWheelMoved){
                switch (e.mouseWheel.delta){
                    case -1:
                        map_view->zoom(2.0f);
                        mywindow->setView(*map_view);
                        break;
                    case 1:
                        map_view->zoom(0.5f);
                        mywindow->setView(*map_view);
                        break;
                    
                }
                
    
}
    
}

void Game::render(sf::RenderWindow* mywindow,float t){
    Time+= t;
    mywindow->setView(*map_view);    
    screen->render(mywindow,t,&rm);
     mywindow->setView(*gui_view);
     screen->renderGUI(mywindow,t,&rm);
    
}
;
}

