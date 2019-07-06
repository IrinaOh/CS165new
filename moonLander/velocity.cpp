#include "velocity.h"

//constructors
Velocity::Velocity(){
   dx = 0;
   dy = 0;
}

Velocity::Velocity(float dx, float dy){
   setDx(dx);
   setDy(dy);
}


//getters
float Velocity::getDx() const{
   return dx;
}

float Velocity::getDy() const{
   return dy;
}


//setters
void Velocity::setDx(float dx){
   this->dx = dx;
}

void Velocity::setDy(float dy){
   this->dy = dy;
}


