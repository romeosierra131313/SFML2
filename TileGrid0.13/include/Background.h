#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "include/Resource.h"
#include <iostream>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Background{
    
    private:
    

    
    public:
        sf::Texture BackGround_T;
    sf::Sprite  BackGround_S;
    int BackGround_X;
    int BackGround_Y;
    int BackGround_D_X;
    int BackGround_D_Y;
    int BackGround_D_Offeset_X;
    int BackGround_D_Offeset_Y;
    romeo::Resource* r;
        
    Background();
    void initia(sf::Vector3i,romeo::Resource*);
    void render(sf::RenderWindow*,float); 
    
    
};
}
#endif
 
