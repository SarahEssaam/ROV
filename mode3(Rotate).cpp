#include "mode.h"

class Rotate : public Mode
{

void do_x(MyJoysickLibrary* myLibrary,QMap* axis){

 *axis["tilt"] = myLibrary->Get_y();
 *axis["rotate"] = myLibrary->Get_r();

}
};
