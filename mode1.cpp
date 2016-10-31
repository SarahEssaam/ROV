#include "mode.h"
#define STEP 0.25

//driving mode

class Driving : public Mode
{
            
void do_x(MyJoysickLibrary* myLibrary){
            x=myLibrary->getAxisPosition(0,X);
            y=myLibrary->getAxisPosition(0,Y);
            
            // neglect small changes in x and y
             if(error_x())
             x=0;
             if(error_y())
             y=0;
                             
            manX=myLibrary->getAxisPosition(0,PovX)*STEP;
            manY=myLibrary->getAxisPosition(0,PovY)*STEP;    
            
            // neglect small changes in manx &y
            if(error_PovX)
            manX=0;
            if(error_PovY)
            manY=0;
     
           }
           
};
