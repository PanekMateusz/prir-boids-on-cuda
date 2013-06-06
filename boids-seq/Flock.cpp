#include "Flock.h"
  
  Flock::Flock(int window_size, int num_boids){
    int i,j;
    row_size =  window_size / CELL_SIZE;
    field_size = window_size;
    size = num_boids;

    flock = (Boid*)malloc(size*sizeof(Boid));
    cell_boid_table.reserve(row_size*row_size);
    breed_boids();
  }

//Rozmieść boidy w losowych punktach
void Flock::breed_boids(){
  int i;
  srand(time(NULL));

  for(i=0; i<size; i++){
    int x = rand()%(field_size+1);
    int y = rand()%(field_size+1);
    
    flock[i] = Boid (x, y);
    insert_boid(x, y, i);
    x = rand()%(2*MAX_SPEED)-MAX_SPEED;
    y = rand()%(2*MAX_SPEED)-MAX_SPEED;
  }
}

void Flock::insert_boid(int x, int y, int id){
  int cell;
//Jak wyleci z pola, wraca z drugiej strony
  if(x > field_size)
  {
    x -= field_size;
  }
  if(y > field_size)
  {
    y -= field_size;
  }
//oczko zawierające boida
  y = y/CELL_SIZE;
  x = x/CELL_SIZE;

  cell = y*row_size+x;
//umieść w tablicy cell/boid
  cell_boid_table[cell].push_back(id);
}
