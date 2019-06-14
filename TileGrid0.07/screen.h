#ifndef SCREEN_H
#define SCREEN_H
#include "Resource.h"
#include <SFML/Graphics.hpp>

namespace romeo{
    
      
    
    
class screen{

    public:
    romeo::Resource resource_manager;
        
        
    screen(){}
    ~screen(){}
    virtual void handleKeys(sf::Event e)=0;
    virtual void render(sf::RenderWindow* mywindow,float)=0; 

};
}
#endif
