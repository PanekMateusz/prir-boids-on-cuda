#include "Flock.h"
  
  Flock::Flock(int window_size, int num_boids){
    int i,j;
    int row_size =  window_size / CELL_SIZE;
    field_size = window_size;
    size = num_boids;
//Alokacja pamięci na tabelę cells/boids
    cell_boid_table = (int**)malloc(row_size*sizeof(int*));
    for(i=0; i<row_size; i++){
      cell_boid_table[i] = (int*) malloc(row_size*sizeof(int));
    }

    for(i=0; i<row_size; i++){
      for(j=0; j<row_size; j++){
        cell_boid_table[i][j] = -1;
      }
    }
    breed_boids();
  }

//Rozmieść boidy w losowych punktach
void Flock::breed_boids(){
  int i;
  srand(time(NULL));
  for(i=0; i<size; i++){
    int x = rand()%(field_size+1);
    int y = rand()%(field_size+1);
    boids_positions.push_back(Point2D(x, y));
    insert_boid(x, y, i);
  }
}

void Flock::insert_boid(int x, int y, int id){
  int i, j;
//Jak wyleci z pola, wraca z drugiej strony
  if(x > field_size)
    x -= field_size;
  if(y > field_size)
    y -= field_size;
//oczko zawierające boida
  i = x / CELL_SIZE;
  j = y / CELL_SIZE;
//umieść w tablicy cell/boid
  cell_boid_table[j][i] = id;
}
