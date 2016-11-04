#include "joystick.h"

Joystick(){
  my_library = new MyJoystickLibrary();
  
  mode[DRIVE] = new Drive();
  mode[MANIP] = new Manip();
  mode[ROTATE] = new Rotate();
  active_mode = mode[DRIVE];
  previous_mode = mode[DRIVE];
  
  init_axis();
  
  timer = new QTimer();
  QObject::connect(this,SIGNAL(timeOut()),this,SLOT(update_states()));
}


update_states{
  update_modes();
  if(active_mode!=previous_mode){
   reset_axis();
   previous_mode = active_mode;
  }
  active_mode->do_x(myLibrary,&current_axis);
  update_buttons();
  tcp_object.send(current_axis);
}


void update_modes(){
}

void update_buttons(){
}

void reset_axis(){
  /*
  QMap<QString, int>::iterator i;
  for (i = current_axis.begin(); i != current_axis.end(); ++i)
    i = 0;
    */
}

//msh sure m7taga a7gz fehom mkan kda wla l2 
void init_axis(){
  current_axis["x"] = 0;
  current_axis["y"] = 0;
  current_axis["z"] = 0;
  current_axis["manX"] = 0;
  current_axis["manY"] = 0;
  current_axis["camera"] = 90;
  current_axis["tilt"] = 0;
  current_axis["rotate"] = 0;
}

void init_modes(){
  mode[DRIVE] = new Drive();
  mode[MANIP] = new Manip();
  mode[ROTATE] = new Rotate();
  active_mode = mode[DRIVE];
  previous_mode = mode[DRIVE];
}
