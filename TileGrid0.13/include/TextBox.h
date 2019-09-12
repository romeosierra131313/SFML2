#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "include/Resource.h"
#include <iostream>
#include <string>
#include <map>
#include <SFML/Graphics.hpp>



namespace romeo{
    
class TextBox{
    
    private:
    int Width;
    int Height;
    int X;
    int Y;
    bool hasFocus;
    
    
    public:
    std::string txt;

    sf::Text TextBoxText;
    sf::Texture* T;
    sf::Sprite S;
    sf::Font fnty;
    sf::Vector3i location;
    romeo::Resource* rm;
    std::map<int,sf::Sprite> TextBoxBack;
    
    TextBox();
    TextBox(std::string,romeo::Resource*);
    void setResource(romeo::Resource*);
    void ResetTextBox(std::string);
    void ResetTextBox(int,int,std::string);
    void ResetTextBox(int,int,int,int,std::string);
    void setTextBoxText(std::string);
    
    void setX(int);
    void setY(int);
    void setHeight(int);
    void setWidth(int);
    void setFocus(bool);
    
    bool getFocus();
    int GetX ();
    int GetY ();
    int GetHeight ();
    int GetWidth ();
    
    
    bool Am_I_Here(sf::Vector2i);
    void render(sf::RenderWindow*,float); 
    
    
};
}
#endif


 
