#ifndef BULLET_H
#define BULLET_H

#define BULLET_LIFE 10000

#include "flyingObject.h"
#include "uiDraw.h"




class Bullet : public FlyingObject
{

public:
   Bullet();
   ~Bullet();

   void draw();
};

#endif // !BULLET_H
