#ifndef FLOCK_H
#define FLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "Boid.h"
#define CELL_SIZE 32;

class Flock {
  int** cell_boid_table;
  int size;
  int field_size;
  Boid* boids;

  public:
    Flock (){};
    Flock (int,int);
    Boid* get_flock(){return boids; };

  private:
    void breed_boids();
};
#endif
