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
    // create pointer to the library we will use
    // MySFML* myLibrary;
    //or MySDL* myLibrary;


};

#endif // JOYSTICK_H
