#include "joystick.h"

Joystick(){
  my_library = new MyJoystickLibrary();
  mode[DRIVE] = new Drive();
  mode[MANIP] = new Manip();
  mode[ROTATE] = new Rotate();
  active_mode = mode[DRIVE];
  previous_mode = mode[DRIVE];
  timer = new QTimer();
  QObject::connect(this,SIGNAL(timeOut()),this,SLOT(update_states()));
}


update_states{
  update_modes();
  if(active_mode!=previous_mode){
   reset_variables();
   previous_mode = active_mode;
  }
//  active_mode->do_x(myLibrary,&current_axis);
  update_buttons();
//  tcp_object.send(&current_axis);
}


void update_modes(){
}

void update_buttons(){
}

reset_variables(){
  /*
  QMap<QString, int>::iterator i;
  for (i = current_axis.begin(); i != current_axis.end(); ++i)
    i = 0;
    */
}
