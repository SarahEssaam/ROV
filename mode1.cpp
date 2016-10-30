#include "mode.h"


//driving mode

Mode1 : public Mode
{

}

void do_x(){
}
x=sf::Joystick::getAxisPosition(0,sf::Joystick::X);
            y=sf::Joystick::getAxisPosition(0,sf::Joystick::Y);
            manX=sf::Joystick::getAxisPosition(0,sf::Joystick::PovX);
            manY=sf::Joystick::getAxisPosition(0,sf::Joystick::PovY);
