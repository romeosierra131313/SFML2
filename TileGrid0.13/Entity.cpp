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
    
    cBattleMenu.initi(64,rm);
    
    
    input_mode = -1;
    TileWidth = rm->TileWidth;
    r = rm;
    Type = T_Type;
    hitbox.setSize(sf::Vector2f(TileWidth,TileWidth));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2);
    
    setLocation(loca);
    setdestination(loca);
    S.setTexture(*(r->getTexture(Type)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    Range_counter = 0;
   
    
}

void Entity::ResetEntity(int T_Type){
    Type = T_Type;
    S.setTexture(*(r->getTexture(Type)));
    sf:: Vector3i temploca = convert_to_Iso(location);
    S.setPosition(temploca.x,temploca.y);
    hitbox.setPosition(temploca.x,temploca.y);
    Range_counter = 0;
   //
    
}
void Entity::setmy_map(std::map<int,romeo::Tile> map){my_map = map;}
int  Entity::getType(){return Type ;}
void Entity::setID(int id){ID = id;}
int  Entity::getID(){return ID ;}
int  Entity::getinput_mode(){return input_mode;}
void Entity::setinput_mode(int new_inputmode){input_mode = new_inputmode;cBattleMenu.menuselection = new_inputmode;}
void Entity::setTexture(sf::Texture* Tex){T= Tex;}
sf::Texture* Entity::getTexture(){return T;}
void Entity::setSprite(sf::Texture* T){S.setTexture(*T);}
void Entity::setLocationZ(int z){location.z = z;}
void Entity::setLocation(sf::Vector3i loca){location = loca;}
sf::Vector3i Entity::getLocation(){return location;}
void Entity::setdestination(sf::Vector3i d){ destination = d;}
sf::Vector3i Entity::getdestination(){ return destination;}
int Entity::getX(){ return getLocation().x;}
int Entity::getY(){ return getLocation().y;}
int Entity::getZ(){ return getLocation().z;}
void Entity::setmove_Range(int i ){ move_Range = i;}
int Entity::getmove_Range(){ return move_Range;}
void Entity::setattack_Range(int i ){ attack_Range = i; }
int Entity::getattack_Range(){ return attack_Range;}

bool Entity::testLocation(sf::Vector3i l){
           for(int j = 0 ; j < 50; j++){
           if(l.x == Range2[j].x && l.y == Range2[j].y){
               return false;
        }
           
    }  return true;
    
}
void Entity::probeLocation(sf::Vector3i loca){
    
    sf::Vector3i tEast(loca.x+1,loca.y,loca.z);
    sf::Vector3i tWest(loca.x-1,loca.y,loca.z);
    sf::Vector3i tNorth(loca.x,loca.y-1,loca.z);
    sf::Vector3i tSouth(loca.x,loca.y+1,loca.z);
    
    
    if(testLocation(tEast)){Range2[Range_counter] = tEast; Range_counter+=1;}
    if(testLocation(tWest)){Range2[Range_counter] = tWest; Range_counter+=1;}
    if(testLocation(tNorth)){Range2[Range_counter] = tNorth; Range_counter+=1;}
    if(testLocation(tSouth)){Range2[Range_counter] = tSouth; Range_counter+=1;}

    
}

void Entity::probeRange(int range){
    probeLocation(location);
    
    for(int i = 0; i <= range; i ++){
        for(int j = 0 ; j < Range_counter; j++){
            probeLocation(Range2[j]);
        }
        
    }
    
}
sf::Vector3i Entity::convert_to_Iso(sf::Vector3i Location){
    sf::Vector3i converted((Location.x+Location.y)*TileWidth/2,((Location.x-Location.y)*(TileWidth*-0.25))-(TileWidth/4)*Location.z, Location.z);
        
        return converted;
        
    }
    
int Entity::makeTileID(int i , int j){ int id = ((i+j)*r->getTileWidth()) + i-j*r->getTileWidth()*0.5 ;return id;}  
void Entity::addRange(sf::Vector3i i ){Range.push(i);}


void Entity::setTime(float t){
    Time = t;
    
}



bool Entity::Am_I_Here(sf::Vector2i here){
        
         if(getX() == here.x && getY() == here.y){
            return true;
        }
        return false;
    }
    
void Entity::handleEvent(romeo::revt e){

    if(e.type == 1 && input_mode == -1){
        if(Am_I_Here(sf::Vector2i(e.iDestinationLocation.x,e.iDestinationLocation.y))){
           cBattleMenu.setFocus(true);
            std::cout << "opening menu"<<std::endl;
           lastTime  =Time;
       }else{ 
           cBattleMenu.menuselection = -2;
           input_mode = -2;
           setinput_mode(-2);
           std::cout << "not here setting input mode to   "<< getinput_mode()<<std::endl;
            std::cout << "not here setting  cBattleMenu.menuselection to   "<<  cBattleMenu.menuselection<<std::endl;
           
           
    }
    }     
    if(e.type == 1 && input_mode == 0){
        std::cout<< " setting destination"<<std::endl;
        setdestination(e.iDestinationLocation);
        lastTime = Time;
       cBattleMenu.menuselection = -1;
       input_mode = -1;
  }  
   if(e.type == 1 && input_mode == -2){
       if(Am_I_Here(sf::Vector2i(e.iDestinationLocation.x,e.iDestinationLocation.y))){
            sethp(-12);
            std::cout << "GOT ATTTACKEDDD  " << e.additionalInformation<<std::endl;
            input_mode = -1;
            cBattleMenu.menuselection = -1;
       }else{ 
           std::cout << "intmode  na" <<input_mode <<std::endl; }
    }   
       
}

void Entity::Update(){
   if(Time-lastTime > 100){ 
    if(location.x != destination.x || location.y != destination.y){
        if(location.x != destination.x){
           if(location.x < destination.x){
               
                int q = makeTileID(getLocation().x-1,getLocation().y);
                romeo::Tile t = my_map[q];
           setLocation(sf::Vector3i(getLocation().x+1,getLocation().y,t.getLocation().z+2));
               
               
        }
           if(location.x > destination.x){
               int q = makeTileID(getLocation().x+1,getLocation().y);
               romeo::Tile t = my_map[q];
               setLocation(sf::Vector3i(getLocation().x-1,getLocation().y,t.getLocation().z+2));
        }
          
           
    }
       if(location.y != destination.y){
           if(location.y < destination.y){
               int q = makeTileID(getLocation().x,getLocation().y-1);
                romeo::Tile t = my_map[q];
                setLocation(sf::Vector3i(getLocation().x,getLocation().y+1,t.getLocation().z+2));
                
                
               
        }
           if(location.y > destination.y){
                int q = makeTileID(getLocation().x,getLocation().y+1);
                romeo::Tile t = my_map[q]; 
                setLocation(sf::Vector3i(getLocation().x,getLocation().y-1,t.getLocation().z+2));
        }
      
    
    }  
    ResetEntity(getType());
    lastTime = Time;    
    
    
    }
    
}
    
    
}







////////////////////////////////////////////////////////////////////////////////////////

int Entity::gethp(){return hp;}
void Entity::sethp(int newHP){hp+=newHP;}
int Entity::getAttack(){return attack;}
void Entity::setAttack(int newAttack){attack+=newAttack;}

////////////////////////////////////////////////////////////////////////////////////////
void Entity::handleKeys(sf::Event e){

     cBattleMenu.handleKeys(e);
    
    
    
}
void Entity::render(sf::RenderWindow* mywindow,float t){
    

    input_mode = cBattleMenu.menuselection;
    setTime(t);
    Update();
    mywindow->draw(S);
    
    
    cBattleMenu.text_hp.setPosition(S.getPosition().x,S.getPosition().y-16);
    cBattleMenu.text_attack.setPosition(S.getPosition().x,S.getPosition().y-32);
    cBattleMenu.text_inputmode.setPosition(S.getPosition().x,S.getPosition().y-48);
    
    cBattleMenu.text_hp.setString("HP : " + std::to_string(gethp()));
    cBattleMenu.text_attack.setString("Attack  : " + std::to_string(getAttack()));
    cBattleMenu.text_inputmode.setString("Inputmode : " + std::to_string(getinput_mode()));
         
    
    mywindow->draw(cBattleMenu.text_hp);
         
         mywindow->draw(cBattleMenu.text_attack);
         
         mywindow->draw(cBattleMenu.text_inputmode);       
 //
     cBattleMenu.render(mywindow,t);
   if(cBattleMenu.getFocus()){

   /// cBattleMenu.render(mywindow,t);
    
}
        
    }
 void Entity::renderHitbox(sf::RenderWindow* mywindow,float t){
        mywindow->draw(hitbox);
     
}

;
} 

