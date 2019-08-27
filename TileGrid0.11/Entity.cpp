#include "include/Entity.h"
#include <map>
#include <iostream>

namespace romeo{
     
     
Entity::Entity(){

}
Entity::Entity(int T_Type,sf::Vector3i loca,romeo::Resource* rm){
    
    //////////////////////////////////////////////////////////////////
    ///////////ISO TILE
    /////////////////////////////////////////////////////////////////
    
    TileWidth = rm->TileWidth;
    r = rm;
    Type = T_Type;
    hitbox.setSize(sf::Vector2f(TileWidth/2,TileWidth/2));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2);
    
    setLocation(loca);
    S.setTexture(*(r->getTexture(Type)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    
    
}

void Entity::ResetEntity(int T_Type){
    Type = T_Type;
    S.setTexture(*(r->getTexture(Type)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    
}

void Entity::setID(int id){ID = id;}
int Entity::getID(){return ID ;}
void Entity::setTexture(sf::Texture* Tex){T= Tex;}
sf::Texture* Entity::getTexture(){return T;}
void Entity::setSprite(sf::Texture* T){S.setTexture(*T);}
void Entity::setLocationZ(int z){location.z = z;}
void Entity::setLocation(sf::Vector3i loca){location = loca;}
sf::Vector3i Entity::getLocation(){return location;}


sf::Vector3i Entity::convert_to_Iso(sf::Vector3i Location){
        sf::Vector3i converted((Location.x+Location.y)*TileWidth/2,
                               ((Location.x-Location.y)*(TileWidth*-0.25))-(TileWidth/4)*Location.z,Location.z);
        
        return converted;
        
    }
    

bool Entity::Am_I_Here(sf::Vector2i here){
        
         if(S.getGlobalBounds().contains(here.x,here.y)){
            return true;
        }
        return false;
    }
void Entity::render(sf::RenderWindow* mywindow,float t){
        
        mywindow->draw(S);
        
        
    }
 void Entity::renderHitbox(sf::RenderWindow* mywindow,float t){
        mywindow->draw(hitbox);
     
}

;
} 

