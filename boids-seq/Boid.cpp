#include "Boid.h"

Boid::Boid(int x, int y){
  srand(time(NULL));
  position = Point2D(x,y);
  int a = rand()%(2*MAX_SPEED)-MAX_SPEED;
  int b  = rand()%(2*MAX_SPEED)-MAX_SPEED;
  velocity = Vector2D(a, b);
  acceleration = Vector2D(0, 0);
}
