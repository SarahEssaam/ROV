#include "mode.h"


//driving mode

Mode1 : public Mode
{
            
}

void do_x(){
            x=myLibrary->getAxisPosition(0,sf::Joystick::X);
            y=myLibrary->getAxisPosition(0,sf::Joystick::Y);
            manX=myLibrary->getAxisPosition(0,sf::Joystick::PovX);
            manY=myLibrary->getAxisPosition(0,sf::Joystick::PovY);
}
           
