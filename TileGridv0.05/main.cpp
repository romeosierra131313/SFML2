#include "pawn.h"
#include "map.h"
#include "battleMenu.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


int tileWidth =64;
int Map_Width;
int Map_Height;
int x;
int y;
int selection = 1;
int mousePressed = 0;
float zoom= 1;
float window_width =1280;
float window_height=720;
 int scale = 4;
 sf::Time t ;
 
sf::RenderWindow window(sf::VideoMode(1280, 720,32), "SFML works!");

sf::View view;
int viewX;
int viewY;
sf::View UI;
sf::Image Tileset_Image;



sf::Vector2i pixelPos;
sf::Font font;
sf::Vector2u Tileset_Size;

 mine::map myMap;
 mine::pawn cursor;
 mine::battlemenu bm;
 




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

Map_Height=21;
Map_Width=21;    
viewX = -((Map_Width*tileWidth)/4);
viewY = 0;
view.reset(sf::FloatRect(viewX,viewY,2048,1152));

view.setCenter(sf::Vector2f((Map_Width/2)*tileWidth,(Map_Height/2)*tileWidth));
view.zoom(zoom);
window.setView(view);
UI.reset(sf::FloatRect(0,0, 1280, 720));


if (!font.loadFromFile("arial.ttf"))
{
    // error...
}
 
if (!Tileset_Image.loadFromFile("assets/terra.png")){
    std::cout << " failed loading TileSet_Image";}    
    
      Tileset_Size = Tileset_Image.getSize();
      
      
      myMap.setTileSet(Tileset_Image,tileWidth);
      myMap.BuildGrid(Map_Width,Map_Height,tileWidth);
      
      
    sf::Texture t;  ///////////////cursor/////////////
    t.loadFromImage(Tileset_Image,sf::IntRect(0,0,tileWidth*2,tileWidth));
    cursor.setup(t,tileWidth,0.25f,sf::Vector2i(4,3));
    cursor.setActive(true);
    view.setCenter( (cursor.location.x*tileWidth),(cursor.location.y));
    
    bm.setup(sf::Vector2i(0,window_height/2),window_width,window_height,font);


}

void drawTiles(float t){
 for (int i = 0;i< Map_Height*Map_Width; i++){
    
       window.draw(myMap.getTile(i,t));
    if(myMap.tile[i].active){
        myMap.tile[i].cursorBox.setFillColor(sf::Color::Black);
        window.draw( myMap.tile[i].cursorBox);
    }
       
  }
}

void drawPawns(float t){
 for (int i = 0;i< myMap.pawncount; i++){
  window.draw(myMap.pawns[i].getSprite(t)); 
         if(myMap.pawns[i].active == true){
                for(int q = 0; q < 64; q++){
                
                    myMap.pawns[i].cursorBox.setOutlineColor(sf::Color::Black);
                    myMap.pawns[i].cursorBox.setOutlineThickness(2.0f);
                    myMap.pawns[i].cursorBox.setPosition(myMap.tileLocation[q].x*64,myMap.tileLocation[q].y*64);
                    window.draw( myMap.pawns[i].cursorBox);
                }
                
            }
  }
}


void drawbattleMenu(){
    if(bm.getActive()){
        std::cout << "active " << std::endl;
       window.draw(bm.back);
       window.draw(bm.moveT);
       window.draw(bm.attackT);
       window.draw(bm.skillsT);
       window.draw(bm.itemsT);
       window.draw(bm.fleeT);}
    
}
void handleKeys(sf::Event Event){
            if(!bm.getActive()){
                 cursor.setActive(true);
            }
            else if(bm.getActive()){
                 cursor.setActive(false);
            }
                       
    
    if (Event.type == sf::Event::KeyPressed){ 
             cursor.move(Event);
             view.setCenter( (cursor.location.x*tileWidth),(cursor.location.y*tileWidth));
             myMap.handleInput(Event,cursor.location);
             bm.handleInput(Event);
           
             
         
       }
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)){//////escape!!//////
                window.close();}

                
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::R)){  ///////reload tileset/////  
               std::cout << " reloaded";

               
                            bool done = false;
                                while(!done){  
                                    
      Tileset_Image.loadFromFile("assets/terra.png") ; 
      myMap.setTileSet(Tileset_Image,tileWidth);
      sf::Texture cursorTexture;
      cursorTexture.loadFromImage(Tileset_Image,sf::IntRect(0,0,tileWidth*2,tileWidth));
      cursor.setup(cursorTexture,tileWidth,0.25f,sf::Vector2i(2,2));
      sf::Texture pawn1;
      pawn1.loadFromImage(Tileset_Image,sf::IntRect(0,tileWidth,tileWidth*3,tileWidth));
      myMap.pawns[0].setTexture(pawn1);  
      myMap.pawns[1].setTexture(pawn1);
                                done = true;      
                                            }
       
        
    }
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Y)){
                selection = 1;
        
    }   
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::U)){//////escape!!//////
                selection = 2;
        
    }   
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::I)){//////escape!!//////
                selection = 3;
        
    }  
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::O)){//////escape!!//////
                selection = 4;
        
    }
     
}

void handleMouseMovement( sf::Event event){
                   
 // get the current mouse position in the window
 pixelPos = sf::Mouse::getPosition(window);
 // convert it to world coordinates
sf::Vector2f position = window.mapPixelToCoords(pixelPos);        
//position = sf::Mouse::getPosition(window);
x= position.x/tileWidth;
y=position.y/tileWidth;
      
        if (event.type == sf::Event::MouseButtonReleased) {
          
      
            mousePressed = 0; 
        }
        
       else if (event.type == sf::Event::MouseButtonPressed) {
           
           
           
          if (event.mouseButton.button == sf::Mouse::Left) {
               mousePressed = 1;
              
            }
       }
       else if(event.type == sf::Event::MouseWheelScrolled)
          
       {
               int mws = event.mouseWheelScroll.delta;
               
                switch(mws){
                    case -1 :
                        if(scale > 0){
                           scale += 1;}
                         break;
                    
                    case  1 :
                        if(scale < 8){
                           scale -= 1;}
                         break;
                }
                          
            }


    
    if(mousePressed == 1){
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
        handleKeys(event);  
        handleMouseMovement(event);  
        
            
        }


       window.clear(sf::Color::Black); 
        sf::Time t = clock.getElapsedTime() ;
       window.setView(view);
       
        drawTiles( t.asSeconds());
        drawPawns( t.asSeconds());
       
       window.draw(cursor.getSprite( t.asSeconds() ));
       
       
       
       window.setView(UI);
       drawbattleMenu();
       
        window.display();
      

        
        
    }
}
int main(){
    doSetup();  
     window.setVerticalSyncEnabled(true);
    Loop();



    return 0;
}
