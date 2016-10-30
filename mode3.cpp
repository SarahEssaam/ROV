#include "mode.h"

class Mode3 : public Mode
{

void do_x(){
 tilt = myLibrary->getAxisPosition(0,Y);
 rotate = myLibrary->getAxisPosition(0,R);

}

//case rotate..
};
