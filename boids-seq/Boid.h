#ifndef BOID_H
#define BOID_H

#include "Structures.h"
#include<stdlib.h>
#include<vector>

#define MAX_SPEED 100
#define RANGE 32

class Boid{
  Point2D position;
  public:
  Vector2D velocity;
  Vector2D acceleration;
  Vector2D separate_force;
  Vector2D align_force;
  Point2D cohesion_sum;
  Vector2D cohesion_force;
  int cell;

  public:
    Boid(){};
    Boid(int, int);
    Point2D get_position(){return position; };
    Vector2D get_velocity(){return velocity; };
    void interact(Boid);
    void sum_forces(int);
    void update(double);
};
#endif
