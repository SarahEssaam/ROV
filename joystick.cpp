
#include mysfml, mysdl, mode1, mode2, mode3 .h

class Joystick 
{
private:
    int activeMode = 0;
    arrayModes[];
    //x,y,povx,povy,z,buttons[],..
    //create pointer to the library we will use(or object from)
    //MySFML / MySDL myLibrary; 
    

Joystick
{
    Mode* arrayModes[MAX];
    arrayModes[0] = new Mode1();
    arrayModes[1] = new Mode2();
    arrayModes[2] = new Mode3();
    //myLibrary = new MySFML or MySDL
    //myLibrary will be sent as a parameter to all the modes
}

void updateModes(){
    //sf::joystick::update()
    //if(sf::joystick::isconnected)

    //the common functions will ither be implemented here or in Mode class
    
    //loop on all modes' buttons and check if isButtonPressed(0,i) set activeMode=mode Pressed
   
    //arrayModes[activeMode]->do_x();
    //recieve the values sent back from do_x()
    //check for the change in those values
    //send them via tcp
}
};
