#include "Flock.h"
  
  Flock::Flock(int window_size, int num_boids){
    int i;
    int row_size =  window_size / CELL_SIZE;
    field_size = window_size;
    size = num_boids;

//Lista boidów
    boids = (Boid*)malloc(size*sizeof(Boid));
//Alokacja pamięci na tabelę cells/boids
    cell_boid_table = (int**)malloc(row_size*sizeof(int*));
    for(i=0; i<row_size; i++){
      cell_boid_table[i] = (int*) malloc(row_size*sizeof(int));
    }
    breed_boids();
  }

//Rozmieść boidy w losowych punktach
void Flock::breed_boids(){
  int i;
  for(i=0; i<size; i++){
    boids[i] = Boid(rand()%(field_size+1), rand()%(field_size+1));    
  }
}
