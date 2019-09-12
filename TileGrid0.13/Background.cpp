#include "include/Background.h"
#include <map>
#include <iostream>

namespace romeo{
     
     
Background::Background(){
        
    BackGround_D_X = 1;
    BackGround_D_Y = 1;
    BackGround_D_Offeset_X = 0;
    BackGround_D_Offeset_Y = 0;

}
void Background::initia(sf::Vector3i loca,romeo::Resource* r){
    
    BackGround_T.loadFromImage(r->return_Back("assets/stand.jpg"));
    BackGround_X=loca.x - ((BackGround_T.getSize().x/2)*3); 
    BackGround_Y=loca.y - ((BackGround_T.getSize().y/2)*4);
    
    BackGround_S.setPosition( BackGround_X,BackGround_Y);
    BackGround_S.setScale(5.f,5.f);
    BackGround_S.setTexture(BackGround_T); 
    
}


void Background::render(sf::RenderWindow* mywindow,float t){
   BackGround_S.move(BackGround_D_X,BackGround_D_Y);
   BackGround_D_Offeset_X = BackGround_D_Offeset_X + BackGround_D_X;
   BackGround_D_Offeset_Y = BackGround_D_Offeset_Y + BackGround_D_Y;
    if(BackGround_D_Offeset_X <= -100 ){
        BackGround_D_X = 1;}
    if(BackGround_D_Offeset_X >=100){
        BackGround_D_X = -1;}
    if(BackGround_D_Offeset_Y <= -50 ){
        BackGround_D_Y = 1;}
    if(BackGround_D_Offeset_Y >=50){
        BackGround_D_Y = -1;}
     mywindow->draw(BackGround_S);
        
    }
;
} 
