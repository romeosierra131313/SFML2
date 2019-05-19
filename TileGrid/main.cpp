#include "pawn.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>


int tileWidth =32;
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
sf::Image Tileset_Image;
sf::Texture Tileset_Texture;
sf::Texture Tile_Texture;
sf::Sprite spr;
sf::Sprite selectPanel;
int Max_Map_Size= 4096;/////////MAX MAP SIZE 64*64/////////////RESET  here///////
sf::Vector3i Grid[4096];////////RESET  here too///////

mine::pawn pawns[32];
int pawncount = 0;
mine::pawn tile[1024];
sf::Texture TextureGrass;
sf::Texture TextureGrass2;
sf::Texture Texturethree;
sf::Texture Texturefour;



sf::Vector3i panel[1000];
sf::Vector2i pixelPos;
sf::Texture* tiles[192];
sf::RectangleShape rsa(sf::Vector2f(64,64));
sf::RectangleShape rsb(sf::Vector2f(32,32));

sf::Vector2u Tileset_Size;
sf::RectangleShape openPanel(sf::Vector2f(60,30));

 mine::pawn cursor;




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
    
view.reset(sf::FloatRect(0,0, 640*4, 360*4));
view.zoom(zoom);
window.setView(view);

Map_Height=21;
Map_Width=21;
 
if (!Tileset_Image.loadFromFile("assets/terra.png")){
    std::cout << " failed loading TileSet_Image";}    
    
      Tileset_Size = Tileset_Image.getSize();
      
    
if (!Tileset_Texture.loadFromImage(Tileset_Image,sf::IntRect(0,0,Tileset_Size.x,Tileset_Size.y))){
    std::cout << " failed loading TileSet_Texture";}
if (!Tile_Texture.loadFromImage(Tileset_Image,sf::IntRect(0,0,tileWidth,tileWidth))){
    std::cout << " failed loading TileSet_Texture";}


      rsa.setPosition(0, 0); 
      rsa.setFillColor(sf::Color::Transparent);
      rsa.setOutlineColor(sf::Color::Black);
      rsa.setOutlineThickness(2);
      
      openPanel.setPosition(Map_Width*tileWidth+tileWidth, 0); 
      openPanel.setFillColor(sf::Color::Black);
      
      rsb.setPosition(Map_Width*tileWidth+tileWidth, 0); 
      rsb.setFillColor(sf::Color::Black);
      
      selectPanel.setTexture(Tileset_Texture);
      selectPanel.setPosition(sf::Vector2f(Map_Width*tileWidth+tileWidth, 0));
      
      spr.setTexture(Tile_Texture);
      
    sf::Texture t;
    t.loadFromImage(Tileset_Image,sf::IntRect(1*tileWidth,0,tileWidth*2,tileWidth));
    cursor.setup(t,tileWidth,0.25f,sf::Vector2i(2,2));
    
    TextureGrass.loadFromImage(Tileset_Image,sf::IntRect(3*tileWidth,0,tileWidth*2,tileWidth));
    TextureGrass2.loadFromImage(Tileset_Image,sf::IntRect(5*tileWidth,0,tileWidth*2,tileWidth));
    Texturethree.loadFromImage(Tileset_Image,sf::IntRect(7*tileWidth,0,tileWidth*2,tileWidth));
    Texturefour.loadFromImage(Tileset_Image,sf::IntRect(9*tileWidth,0,tileWidth*2,tileWidth));
    
    sf::Texture t2;
    t2.loadFromImage(Tileset_Image,sf::IntRect(32,32,tileWidth*3,tileWidth));
    pawns[0].setupPawn(t2,tileWidth,0.25f,sf::Vector2i(4,4),3);
    pawns[1].setupPawn(t2,tileWidth,0.25f,sf::Vector2i(10,10),4);
    pawncount = 2;


}
void handleKeys(sf::Event Event){
    
    if (Event.type == sf::Event::KeyPressed){ 
             cursor.move(Event);
         
       }
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)){//////escape!!//////
                window.close();}
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Z)){
            std::cout << " Z" << std::endl;
                   for (int i = 0;i< pawncount; i++){
                        if(cursor.location.x == pawns[i].location.x){
                          if(cursor.location.y == pawns[i].location.y){  
                              sf::Vector2i m(0,0);
                              std::cout << " found" << std::endl;
                              m.x = pawns[i].location.x + pawns[i].myRange;
                              m.y = pawns[i].location.y;
                             pawns[i].destination=m;
                        }
                   }                     
            }                          
        
    }
                
    if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::R)){  ///////reload tileset/////  
               std::cout << " reloaded";

               
                            bool done = false;
                                while(!done){  
                                    
      Tileset_Image.loadFromFile("assets/terra.png") ; 
      Tileset_Size = Tileset_Image.getSize();
      Tileset_Texture.loadFromImage(Tileset_Image,sf::IntRect(0,0,Tileset_Size.x,Tileset_Size.y));
      TextureGrass.loadFromImage(Tileset_Image,sf::IntRect(3*tileWidth,0,tileWidth*2,tileWidth));
      TextureGrass2.loadFromImage(Tileset_Image,sf::IntRect(5*tileWidth,0,tileWidth*2,tileWidth));   
      sf::Texture cursorTexture;
      cursorTexture.loadFromImage(Tileset_Image,sf::IntRect(1*tileWidth,0,tileWidth*2,tileWidth));
      cursor.setup(cursorTexture,tileWidth,0.25f,sf::Vector2i(2,2));
      sf::Texture pawn1;
      pawn1.loadFromImage(Tileset_Image,sf::IntRect(32,32,tileWidth*3,tileWidth));
      pawns[0].setTexture(pawn1);  
      pawns[1].setTexture(pawn1);
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
void buildGrid(){
     int count = 0;
for (int i = 0;i< Map_Width; i++){   ///////setup grid to draw on////
    for (int j = 0;j< Map_Height; j++){
    
    tile[count].myType = 1;
    tile[count].setup(TextureGrass,tileWidth,0.25f,sf::Vector2i(i,j));

count++;
 
}    
    
}

}

void drawTiles(float t){
 for (int i = 0;i< Map_Height*Map_Width; i++){
       window.draw(tile[i].getSprite(t));
       rsa.setFillColor(sf::Color::Transparent);
       rsa.setPosition(sf::Vector2f(tile[i].location.x*tileWidth, tile[i].location.y*tileWidth));  
       window.draw(rsa);
  }
}
void drawPawns(float t){
 for (int i = 0;i< pawncount; i++){
       
       pawns[i].moveTo();
       
        for (int j = 0;j< 64; j++){
        rsb.setFillColor(sf::Color::Blue);
        rsb.setPosition(sf::Vector2f(pawns[i].movementRange[j].x*tileWidth, pawns[i].movementRange[j].y*tileWidth));  
       window.draw(rsb);
  }
  
  window.draw(pawns[i].getSprite(t)); 
  
  }
}
void drawPanel(){
    window.draw(rsb);
    window.draw(selectPanel);
    
}
void drawPanelButton(){

     
    openPanel.setPosition(1200,20);
    openPanel.setFillColor(sf::Color::Red);
    window.draw(openPanel);
    
}
void setTileToSelection(int x,int y){
    
    for (int i = 0;i<= Map_Height*Map_Width-1; i++){
          if(tile[i].location.x == x  ){
            if(tile[i].location.y == y  ){
                     tile[i].myType = selection;  
                     switch(selection){
                         case 1:tile[i].setup(TextureGrass,tileWidth,0.25f,sf::Vector2i(x,y));
                             
                             break;
                         case 2:tile[i].setup(TextureGrass2,tileWidth,0.25f,sf::Vector2i(x,y));
                             
                             break;
                         case 3:tile[i].setup(Texturethree,tileWidth,0.25f,sf::Vector2i(x,y));
                             
                             break;
                         case 4:tile[i].setup(Texturefour,tileWidth,0.25f,sf::Vector2i(x,y));
                             
                             break;
                         
                    }
                     break;
              }
            }   
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
              switch(scale){
                    case 1 :view.reset(sf::FloatRect(0, 0,240,160));
                            window.setView(view);
                           
                         break;
                    
                    case  2 :
                            view.reset(sf::FloatRect(0, 0,960,540));
                            window.setView(view);
                         break;
                    
                    case 3 :view.reset(sf::FloatRect(0, 0,1024,576));
                            window.setView(view);
                           
                         break;
                    
                    case  4 :
                            view.reset(sf::FloatRect(0, 0,1280,720));
                            window.setView(view);
                         break;
                         
                    case 5 :view.reset(sf::FloatRect(0, 0,1366,768));
                            window.setView(view);
                           
                         break;
                    
                    case  6 :
                            view.reset(sf::FloatRect(0, 0,1600,900));
                            window.setView(view);
                         break;
                    
                    case 7 :view.reset(sf::FloatRect(0, 0,1920,1080));
                            window.setView(view);
                           
                         break;
                    
                    case  8 :
                            view.reset(sf::FloatRect(0, 0,2048,1152));
                            window.setView(view);
                         break;     
                }
                       
            


	
//2560 	1440 	
//2880 	1620 	
//3200 	1800 	
//3840 	2160 	


    
    if(mousePressed == 1){
            setTileToSelection(x,y);
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

        drawTiles( t.asSeconds());
        drawPawns( t.asSeconds());
       window.setView(window.getDefaultView());
       window.setView(view);
       drawPanel();
       
       
       window.draw(cursor.getSprite( t.asSeconds() ));
       
       pawns[0].getSprite( t.asSeconds() ).setColor(sf::Color::Blue);
       window.draw(pawns[0].getSprite( t.asSeconds() ));
       
        window.display();
      

        
        
    }
}
int main(){
    doSetup();
    buildGrid();   
     window.setVerticalSyncEnabled(true);
   
    Loop();



    return 0;
}
