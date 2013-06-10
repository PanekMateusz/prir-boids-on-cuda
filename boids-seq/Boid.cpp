#include "Boid.h"

Boid::Boid(int x, int y){
  position = Point2D(x,y);
  int a = rand()%(2*MAX_SPEED)-MAX_SPEED;
  int b  = rand()%(2*MAX_SPEED)-MAX_SPEED;
  velocity = Vector2D(a, b);
  acceleration = Vector2D(0, 0);
  separate_force = Vector2D(0, 0);
  align_force = Vector2D(0, 0);
  cohesion_sum = Point2D(0, 0);
  cohesion_force = Vector2D(0, 0);
}
void Boid::reset_forces(){
  separate_force = Vector2D(0, 0);
  align_force = Vector2D(0, 0);
  cohesion_sum = Point2D(0, 0);
  cohesion_force = Vector2D(0, 0);
}
void Boid::interact(Boid b){
  Vector2D diff (position.x - b.get_position().x , position.y - b.get_position().y);

  cohesion_sum.x += b.get_position().x;
  cohesion_sum.y += b.get_position().y;

  separate_force = separate_force + diff;
  align_force = align_force + b.velocity;
}

void Boid::sum_forces(int size){
  if(size >0){
    separate_force.x /= size;
    separate_force.y /= size;
    
    align_force.x /= size;
    align_force.y /= size;

    cohesion_sum.x /= size;
    cohesion_sum.y /= size;
    cohesion_sum.x -= position.x;
    cohesion_sum.y -= position.y;

    cohesion_force.x = cohesion_sum.x - velocity.x;
    cohesion_force.y = cohesion_sum.y - velocity.y;
  }

  Vector2D force = separate_force + cohesion_force + align_force;

  acceleration.x *= 0.2;
  acceleration.y *= 0.2;
  acceleration = acceleration + force;
}

void Boid::update(double time, int field){
  velocity.x = velocity.x + (acceleration.x * time);
  velocity.y = velocity.y + (acceleration.y * time);

  position.x += velocity.x * time; //nowe pozycje + upewnij się że zotajesz w polu
  if( position.x > field){
    position.x -= field;
  }else if( position.x < 0 ){
    position.x += field;
  }
  position.y += velocity.y * time;
  if( position.y > field){
    position.y -= field;
  }else if( position.y < 0 ){
    position.y += field;
  }
}
