#ifndef FLOCK_H
#define FLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<list>
#include "Structures.h"

#define CELL_SIZE 32;

class Flock {
  int** cell_boid_table;
  int size;
  int field_size;
  list<Point2D> boids_positions;

  public:
    Flock (){};
    Flock (int,int);
    list<Point2D> get_flock_positions(){return boids_positions; };
    

  private:
    void breed_boids();
};
#endif
