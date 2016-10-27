#include "joystick.h"

Joystick::Joystick(QObject *parent) : QObject(parent)
{

    QObject::connect(this,SIGNAL(//initiate mode1 signal),object from class mode1,SLOT(Do mode1 slot));
    QObject::connect(this,SIGNAL(//initiate mode2 signal),object from class mode2,SLOT(Do mode2 slot));
    QObject::connect(this,SIGNAL(//initiate mode3 signal),object from class mode3,SLOT(Do mode3 slot));
    QObject::connect(this,SIGNAL(timeout()),this,SLOT(updateModes)));


    //myLibrary = new MySFML or MySDL
    //myLibrary will be sent as a parameter to all the modes


}

void updateModes(){
    //sf::joystick::update()
    //if(sf::joystick::isconnected)

    //check on general functions' (that are not tied to a mode)
    //like tilt, rotate, camera, stablization, (sensitivity?), (fe 7aga tania?)

    //loop on all modes' buttons and check if isButtonPressed set activeMode=mode Pressed
    //emit signal for the active mode

    //recieve the values sent from Do mode
    //check for the change in those values
    //send them via tcp

}
