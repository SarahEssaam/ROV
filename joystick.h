#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <QObject>
#include mysfml, mysdl, mode1, mode2, mode3 .h

class Joystick : public QObject
{
    Q_OBJECT
public:
    explicit Joystick(QObject *parent = 0);

signals:

public slots:
    void updateModes();

private:
    int activeMode = 0;
    mode[];
    //x,y,povx,povy,z,buttons[],..
    // create pointer to the library we will use(or object from)
    //MySFML / MySDL myLibrary; 
    //timer

};

#endif // JOYSTICK_H
