#ifndef BIRD_H
#define BIRD_H

#include "flyingObject.h"
#include "uiDraw.h"

class Bird : public FlyingObject
{
private:
   int life;
   int hitPoint;
   int id;

public:
   Bird();
   int hit();

   void setLife(int l)
   {
      this->life = l;
   }

   int getLife() const
   {
      return life;
   }

   void setHitPoint(int hP)
   {
      this->hitPoint = hP;
   }

   int getHitPoint() const
   {
      return hitPoint;
   }

   void setID(int i)
   {
      this->id = i;
   }

   int getID() const
   {
      return id;
   }
};

class standardBird : public Bird
{
private:
public:
   standardBird();
   void draw();
   int hit() const
   {
      return getHitPoint();
   }
};

class toughBird : public Bird
{
private:
public:
   toughBird();
   void draw();
   int hit() const
   {
      return getHitPoint();
   }
};

class sacredBird : public Bird
{
private:
public:
   sacredBird();
   void draw();
   int hit() const
   {
      return getHitPoint();
   }
};

#endif // !BIRD_H
