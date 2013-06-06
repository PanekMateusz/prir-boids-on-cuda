#ifndef BOID_H
#define BOID_H

#include "Structures.h"

#define RANGE 32;

class Boid{
  Point2D position;

  public:
    Boid(){};
    Boid(int, int);
    Point2D get_position(){return position; };
};
#endif
