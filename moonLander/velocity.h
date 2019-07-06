#ifndef VELOCITY_H
#define VELOCITY_H


class Velocity
{
public:
	//Constructors
   Velocity();
   Velocity(float dx, float dy);
 
   
   //Getters
   float getDx() const;
   float getDy() const;
 
   
   //Setters
   void setDx(float dx);
   void setDy(float dy);
   
   
private:
	float dx;
	float dy;
};

#endif // !VELOCITY_H

