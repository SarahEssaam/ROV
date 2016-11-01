#include "mode.h"
#define STEP 0.1

//manipulator mode

class Manip : public Mode
{
            
void do_x(MyJoysickLibrary* myLibrary,QMap* axis){

            axis["manX"]=myLibrary->Get_x();
            axis["manY"]=myLibrary->Get_y();
                   
            axis["x"]=myLibrary->Get_povx()*STEP;
            axis["y"]=myLibrary->Get_povy()*STEP;    
 
           }
           
};
