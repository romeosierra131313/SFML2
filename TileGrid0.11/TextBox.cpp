#include "include/TextBox.h"
#include <iostream>

namespace romeo{
     
     
TextBox::TextBox(){


} 

TextBox::TextBox(std::string g,romeo::Resource* r){
    rm = r;
    txt = g;
    ResetTextBox(4,3,3,1, g);



}
    
void TextBox::ResetTextBox(std::string g){
     
     setTextBoxText(g);
    
        int count = 0;
    for(int i = 0 ; i < 3; i++){
      for(int j = 0 ; j < 2; j++){  
        sf::Sprite s;
        s.setTexture(*(rm->getTexture(6)));
        s.setPosition(rm->getTileWidth()*i,rm->getTileWidth()*j);
        TextBoxBack.insert(std::make_pair( count,s));
        count++;    
    }
    }  
    
}

void TextBox::setResource(romeo::Resource* r){
       rm = r ;
        
    }

    
void TextBox::ResetTextBox(int length,int height ,std::string g){
    
     setTextBoxText(g);
    
        int count = 0;
    for(int i = 0 ; i < length+1; i++){
      for(int j = 0 ; j < height+1; j++){  
        sf::Sprite s;
        s.setTexture(*(rm->getTexture(6)));
        s.setPosition(rm->getTileWidth()*i,rm->getTileWidth()*j);
        TextBoxBack.insert(std::make_pair( count,s));
        count++;    
    }
    }  
    
}

void TextBox::ResetTextBox(int x,int y,int length,int height ,std::string g){
    
    setX(x);
    setY(y);
    setHeight(length);
    setWidth(height);
    
     int TW = rm->getTileWidth();
     setTextBoxText(g);
     TextBoxText.setPosition(x*TW+TW/2,y*TW+TW/4);
        int count = 0;
    for(int i = 0 ; i < length; i++){
      for(int j = 0 ; j < height; j++){  
        sf::Sprite s;
        s.setTexture(*(rm->getTexture(6)));
        s.setPosition( (TW*x) + (TW*i),(TW*y)+(TW*j));
        TextBoxBack.insert(std::make_pair( count,s));
        count++;    
    }
    }  
    
}

void TextBox::setTextBoxText(std::string g){
     txt = g;
     TextBoxText.setFont(*rm->getFont());
     TextBoxText.setString(g);
     TextBoxText.setCharacterSize(24);
     TextBoxText.setFillColor(sf::Color::Black);
    
}



void TextBox::setX(int x){X = x;}
void TextBox::setY(int y){Y = y;}
void TextBox::setHeight(int height){Height = height;}
void TextBox::setWidth(int width){Width = width;}
int TextBox::GetX (){return X;}
int TextBox::GetY (){return Y;}
int TextBox::GetHeight (){return Height;}
int TextBox::GetWidth (){return Width;}



    
bool TextBox::Am_I_Here(sf::Vector2i click){
    for(int i = 0; i < TextBoxBack.size(); i++){
    if(TextBoxBack[i].getGlobalBounds().contains(click.x,click.y)){
        std::cout <<"true";
        return true;
    }
    
    }
        return false;
}
    
void TextBox::render(sf::RenderWindow* mywindow,float t){
           for(int i = 0 ; i < TextBoxBack.size(); i++){
        mywindow->draw(TextBoxBack[i]);
        
        }

        mywindow->draw(TextBoxText);       
    }

}
