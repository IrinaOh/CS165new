#include "lander.h"

//Cosntructors
Lander::Lander()
{
   setAlive(true);
   setLanded(false);
   velocity.setDx(0.0);
   velocity.setDy(0.0);
   
}

Lander::Lander(Point point, Velocity velocity, int fuel)
{
   setPoint(point);
   setLanded(false);
   setFuel(fuel);
   setAlive(true);
   setLanded(false);
}

//Getters
Point Lander::getPoint() const{
   return point;
}

Velocity Lander::getVelocity() const{
   return velocity;
}

int Lander::getFuel() const{
   return fuel;
}

bool Lander::isAlive() const{
   return alive;
}

bool Lander::isLanded() const{
   return landed;
}


//Setters
void Lander::setPoint(Point point){
   this->point = point;
}

void Lander::setVelocity(Velocity velocity){
   this->velocity = velocity;
}

void Lander::setFuel(int fuel){
   this->fuel = fuel;
}

void Lander::setAlive(bool alive){
   this->alive = alive;
}

void Lander::setLanded(bool landed){
   this->landed = landed;
}


//Others
bool Lander::canTrust(){
   return true;
}

void Lander::applyGravity(float gravity){
   velocity.setDy(velocity.getDy() - gravity);
}

void Lander::applyTrustLeft(){
   if (fuel > 0){
      velocity.setDx(velocity.getDx() + 0.1);
      setFuel(fuel - 1);
      drawLanderFlames(point, false, false, true);
   }
}

void Lander::applyTrustRight(){
   if (fuel > 0){
      velocity.setDx(velocity.getDx() - 0.1);
      setFuel(fuel - 1);
      drawLanderFlames(point, false, false, true);
   }
}

void Lander::applyTrustBottom(){
   if (fuel >= 3){
      velocity.setDy(velocity.getDy() + 0.3);
      setFuel(fuel - 3);
      drawLanderFlames(point, true, false, false);
   }
}

void Lander::advance(){
   point.setX(point.getX() + velocity.getDx());
   point.setY(point.getY() + velocity.getDy());
}

void Lander::draw(){
   drawLanderFlames(point, true, true , true);
}
