 
#include <SFML/Graphics.hpp>
#include "stdlib.h"

float Screen_Width = 700.0f;
float Screen_Height = 700.0f
int Snake_X,Snake_Y;
sf::RectangleShape Snake_Head(sf::Vector2f(32,32));
bool right = false;
bool left  = false;
bool up = false;
bool down = false;
sf::RectangleShape* Snake[500];
int Score;

sf::RectangleShape Apple(sf::Vector2f(32,32));

void resetDirections(){
   bool right = false;
   bool left  = false;
   bool up = false;
   bool down = false;
}
void doSetup(){
    Snake_X = Sceen_Width/2;
    Snake_Y = Screen_Height/2;
    Snake_Head.setPostion(Snake_X,Snake_Y);
    Snake_Head.setFillColor(sf::Color::Green);
    Snake[0] = *Snake_Head;
    right = true;
 
    
    Apple.setPostion((rand()%640)%32,(rand()%640)%32);
    Apple.setFillColor(sf::Color::Red);
 
    
 
 
}
void addSnakePiece(){
    Snake[score] = *sf::RectangleShape(32,32);
    Snake[score]->setPosition(Snake_X,Snake_Y);
}
void DrawSnake(){
    for(int i =0 ; i < score; i++){
       window.Draw(*Snake[i]);
    }
}
void PlaceApple(){
    Apple.setPostion((rand()%640)%32,(rand()%640)%32);

}
void DoMovement(){
 
 ///////do later ////
 ////last snake piece position///
 ////to second last /////
 ////second last to third etc ///////
   if(up){
     Snake_Y += 5;}
 else if(down){
     Snake_Y -= 5;}
 else if(right){
     Snake_X += 5;}
 else if(left){
     Snake_X -= 5;}
}

void HandleInput(sf::Event event){
   if(event == sf::Event::KeyPressed){
     if(event.key.code == sf::Keyboard::W){
       up = true;
   }
     if(event.key.code == sf::Keyboard::S){
       down =true;
   }
     if(event.key.code == sf::Keyboard::A){
       left = true;
   }
     if(event.key.code == sf::Keyboard::D){
       right = true;
   }
 }
 
void DetectCollision(){
    const bool collides = Snake[0].getGlobalBounds().intersect(Apple.getGlobalBounds());
    if(collides){
      score++;
     addSnakePiece();
      PlaceApple();
    }
 
    
}
void MainGameLoop(){
      sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        HandleInput(event);
        DoMovement();
        DetectCollision();
        DrawSnake();
        window.clear();
        
        window.display();
    }

}
int main()
{
    doSetup();
    MainGameLoop();
    return 0;
}
