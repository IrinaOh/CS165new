#ifndef LANDER_H
#define LANDER_H

#include "uiDraw.h"
#include "uiInteract.h"
#include "point.h"
#include "velocity.h"

class Lander
{

public:
	// Constructors
   Lander();
   
   Lander(Point point, Velocity velocity, int fuel);

   
   // Getters
   Point getPoint() const;
   Velocity getVelocity() const;
   int getFuel() const;
	bool isAlive() const;
   bool isLanded() const;
   
   
   // Setters
   void setLanded(bool isLanded);
   void setAlive(bool isAlive);
   void setFuel(int fuel);
   void setVelocity(Velocity velocity);
   void setPoint(Point Point);
   
   
   //Others
   bool canTrust();
   
	void applyGravity(float gravity);
	void applyTrustLeft();
	void applyTrustRight();
	void applyTrustBottom();
	void advance();
	void draw();

   
private:
	Point point;
	Velocity velocity;
	
   bool alive;
	bool landed;
	
   int fuel;

};

#endif // !LANDER_H

