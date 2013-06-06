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

class Flock {
  int size;
  int field_size;
  int row_size;

  vector< vector<int> > neighbours;
  vector< vector<int> > cell_boid_table;
  public:
    Boid* flock;
    Flock (){};
    Flock (int,int);
    void update_flock();
  private:
    void breed_boids();
    void insert_boid(int,int,int);
    vector<int> find_near(int, int, int);
};
#endif
