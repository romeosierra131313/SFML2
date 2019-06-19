#include "Resource.h"
#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>


 
sf::RenderWindow window(sf::VideoMode(1440,1280), "SFML works!");
sf::View gui_view(sf::FloatRect(360,200, 720, 480));
sf::View map_view(sf::FloatRect(360,200, 1440, 1280));
romeo::Resource Resource_Manager;
romeo::Game game;

/*
void gluPerspective(double fovy,double aspect, double zNear, double zFar)
{
 // Start in projection mode.
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 double xmin, xmax, ymin, ymax;
 ymax = zNear * tan(fovy * M_PI / 360.0);
 ymin = -ymax;
 xmin = ymin * aspect;
 xmax = ymax * aspect;
 glFrustum(xmin, xmax, ymin, ymax, zNear, zFar);
}*/

void doSetup(){

// std::cout<<"setting viewport" << std::endl;
// view.reset(sf::FloatRect(x,y, 1440, 1280));
// std::cout<<"setting window" << std::endl;
// window.setView(view);
// window.setFramerateLimit(60);
game.setWindow(&window,&gui_view,&map_view);




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


       window.clear(sf::Color::Blue); 
        
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
