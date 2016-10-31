
Joystick(){
  my_library = new mySFML();
  mode[DRIVE] = new drive();
  mode[MANIP] = new manip();
  mode[ROTATE] = new rotate();
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
  active_mode->do_x(myLibrary);
  update_buttons();
  tcp_send();
}


void update_modes(){
}

void tcp_send(){}

void update_buttons(){
}

reset_variables(){
  
}
