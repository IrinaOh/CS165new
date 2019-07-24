#ifndef VELOCITY_H
#define VELOCITY_H


//Put your velocity class here, or overwrite this file with your own
//velocity class from the previous project

class Velocity 
{

private:
	float x = 0;
	float y = 0;

public:
	Velocity() { setDx(0); setDy(0); }
	Velocity(float x, float y) { setDx(x); setDy(y); }

	float getDx() const { return x; }
	float getDy() const { return y; }

	void setDx(float x) { this->x += x; }
	void setDy(float y) { this->y += y; }

};


#endif // !VELOCITY_H
