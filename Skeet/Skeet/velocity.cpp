#include "velocity.h"

Velocity::Velocity()
{
}

Velocity::~Velocity()
{
}

void Velocity::calcAngle()
{
   dX = speed * (-cos(M_PI / 180.0 * angle));
   dY = speed * (sin(M_PI / 180.0 * angle));
}
