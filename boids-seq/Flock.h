#ifndef FLOCK_H
#define FLOCK_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<list>
#include<vector>
#include "Structures.h"


#define CELL_SIZE 32
#define MAX_SPEED 100

class Flock {
  int size;
  int field_size;
  int row_size;

  list<Point2D> boids_positions;
  list<Vector2D> boids_separations;
  list<Vector2D> boids_aligments;
  list<Vector2D> boids_cohesions;

  list<Vector2D> boids_accelerations;
  list<Vector2D> boids_velocities;
  vector< vector<int> > cell_boid_table;
  public:
    Flock (){};
    Flock (int,int);
    list<Point2D> get_flock_positions(){return boids_positions; }; 

  private:
    void breed_boids();
    void insert_boid(int,int,int);
};
#endif
