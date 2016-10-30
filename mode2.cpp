#include "mode.h"
#define STEP 0.1

//manipulator mode

class Mode2 : public Mode
{
            
void do_x(){
            manX=myLibrary->getAxisPosition(0,X);
            manY=myLibrary->getAxisPosition(0,Y);
            
            // neglect small changes in x and y
             if(error_x())
             manX=0;
             if(error_y())
             manY=0;
                             
            x=myLibrary->getAxisPosition(0,PovX)*STEP;
            y=myLibrary->getAxisPosition(0,PovY)*STEP;    
            
            // neglect small changes in manx &y
            if(error_PovX)
            x=0;
            if(error_PovY)
            y=0;
     
           }
           
};
