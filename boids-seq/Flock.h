#ifndef FLOCK_H
#define FLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<list>
#include<vector>
#include "Structures.h"
#include "Boid.h"

#define CELL_SIZE 32
#define MAX_SPEED 100

class Flock {
  int size;
  int field_size;
  int row_size;

  Boid* flock;
  vector< vector<int> > cell_boid_table;
  public:
    Flock (){};
    Flock (int,int);

  private:
    void breed_boids();
    void insert_boid(int,int,int);
};
#endif
