//parent class to all modes
#define MIN_X 1
#define MIN_POV 5


class Mode{
public:
virtual void do_x(){}
bool error_x(){
  if((myLibrary->getAxisPosition(0,X)<MIN_X)&&(myLibrary->getAxisPosition(0,X)>-1*MIN_X))
  return true;
}
  bool error_y(){
  if((myLibrary->getAxisPosition(0,y)<MIN_X)&&(myLibrary->getAxisPosition(0,y)>-1*MIN_X))
  return true;
}
  bool error_PovX(){
  if((myLibrary->getAxisPosition(0,PovX)<MIN_POV)&&(myLibrary->getAxisPosition(0,PovX)>-1*MIN_POV))
  return true;
}
  bool error_PovY(){
  if((myLibrary->getAxisPosition(0,PovY)<MIN_POV)&&(myLibrary->getAxisPosition(0,PovY)>-1*MIN_POV))
  return true;
}
  
  
  
  

};
