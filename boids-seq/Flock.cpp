#include "Flock.h"
  
  Flock::Flock(int window_size, int num_boids){
    int i,j;
    row_size =  window_size / CELL_SIZE;
    field_size = window_size;
    size = num_boids;

    flock = (Boid*)malloc(size*sizeof(Boid));
    neighbours.reserve(size);
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
    Boid b (x, y); 
    flock[i] = b;
    //insert_boid(x, y, i);
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

void Flock::update_flock(double time){
  rebuild_table();
  vector<int> near_boids;
  for(int i=0; i<size; i++){
    near_boids.clear();
    near_boids = find_near(flock[i].get_position().x, flock[i].get_position().y, i);
    neighbours[i] = near_boids;
    for(int j=0; j < near_boids.size(); j++){
      flock[i].interact(flock[near_boids[j]]);
    }
    flock[i].sum_forces(near_boids.size());
    flock[i].update(time);
    near_boids.clear();
  }
}

vector<int> Flock::find_near(int x, int y, int id){
  int cell_i, cell_j;
  vector<int> n_b;
  int cell = (y/CELL_SIZE)*row_size+(x/CELL_SIZE);
  int i = cell/row_size;
  int j = cell- (i*row_size);
  i--;
  j--;
  for(int ii=i; ii<(i+3); ii++){
    if(ii<0){
      cell_i = row_size+ii;
    }else if(ii >= row_size){
      cell_i = ii-row_size;
    }else{
      cell_i = ii;
    }
    for(int jj=j; jj<(j+3); jj++){ //Sprawdź 9 sąsiednich komórek
      if(jj<0){
        cell_j = row_size+jj;
      }else if(jj >= row_size){
        cell_j = jj-row_size;
      }else{
        cell_j = jj;
      } 
      for(int k=0; k < cell_boid_table[(cell_i*row_size)+cell_j].size(); k++){ //boidy wewnątrz sąsiadującej komórki
        int neighbour_boid = cell_boid_table[(cell_i*row_size)+cell_j][k];
        double distance, distance_x, distance_y;
	distance_x = abs(flock[neighbour_boid].get_position().x - x);
	distance_y = abs(flock[neighbour_boid].get_position().y - y);
	if(jj <0){
          distance_x -= field_size;
	}
	if(ii < 0){
          distance_y -= field_size;
	}
  	distance = sqrt( distance_x*distance_x + distance_y*distance_y );
	if(distance <= CELL_SIZE/2 && neighbour_boid != id){
	  n_b.push_back(neighbour_boid);
	}
      }
    }
  }

  return n_b;
}

void Flock::rebuild_table(){
  
  for(int i=0; i<row_size*row_size; i++){
    cell_boid_table[i].clear();
  }
  for(int i=0; i<size; i++){
    neighbours[i].clear();
    insert_boid(flock[i].get_position().x, flock[i].get_position().y, i);  
  }
}
