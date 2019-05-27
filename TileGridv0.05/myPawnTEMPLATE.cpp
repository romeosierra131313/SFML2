

#include "pawn.h"
#include "myPawn.h"
#include <iostream>

namespace mine{
         myPawn::myPawn():pawn{}{
         std::cout<<"im constructed!!!"<< std::endl;
         
    };
         void myPawn::doathin(){
             std::cout<<"im ALIVE!!!"<< std::endl;
             
        } 
             
             

}
