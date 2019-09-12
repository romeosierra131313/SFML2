#ifndef ENTITY_H
#define ENTITY_H
#include "include/revt.h"
#include "include/BattleMenu.h"
#include "include/Resource.h"
#include <iostream>
#include "include/Tile.h"
#include <queue>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class Entity{
    
    private:
    int ID;
    int Type;
    sf::RectangleShape hitbox;
    sf::Texture* T;
    sf::Sprite S;
    sf::Vector3i location;
    sf::Vector3i destination;
    int TileWidth;
    romeo::Resource* r;
    
    
     int attack_Range;
     int move_Range;
     int input_mode;
     
     int hp;
     int attack;
     

    
    public:
        float Time;
        float lastTime;
        std::map<int,romeo::Tile> my_map;
        sf::Vector2i range[50] ;
        std::queue<sf::Vector3i> Range;
        sf::Vector3i Range2[50];
        int Range_counter;
        romeo::BattleMenu cBattleMenu;
    
    Entity();
    Entity(int,sf::Vector3i,romeo::Resource*);
    void ResetEntity(int);
    void setmy_map(std::map<int,romeo::Tile>);
    
    int getType();
    void setID(int);
    int getID();
    int getinput_mode();
    void setinput_mode(int);
    int gethp();
    void sethp(int);
    int getAttack();
    void setAttack(int); 
    void setTexture(sf::Texture*);
    sf::Texture* getTexture();
    void setSprite(sf::Texture*);
    
    sf::Vector3i convert_to_Iso(sf::Vector3i);
    void setLocationZ(int);
    void setLocation(sf::Vector3i);
    sf::Vector3i getLocation();
    void setdestination(sf::Vector3i);
    sf::Vector3i getdestination();
    int getX();
    int getY();
    int getZ();
    void setattack_Range(int);
    int getattack_Range();
    void setmove_Range(int);
    int getmove_Range();
    int makeTileID(int,int);
    void setTime(float);
    bool Am_I_Here(sf::Vector2i);
    void handleEvent(romeo::revt);
    void Update();
    bool testLocation(sf::Vector3i);
    void addRange(sf::Vector3i);
    void probeLocation(sf::Vector3i);
    void probeRange(int);
    void handleKeys(sf::Event);
    void render(sf::RenderWindow*,float); 
    void renderHitbox(sf::RenderWindow*,float);
    
    
};
}
#endif


 
