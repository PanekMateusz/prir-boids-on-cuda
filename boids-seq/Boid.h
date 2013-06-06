#ifndef BOID_H
#define BOID_H

#include "Structures.h"
#include<stdlib.h>

#define MAX_SPEED 100
#define RANGE 32

class Boid{
  Point2D position;
  Vector2D velocity;
  Vector2D acceleration;

  public:
    Boid(){};
    Boid(int, int);
    Point2D get_position(){return position; };
};
#endif
