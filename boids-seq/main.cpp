#include "main.h"

int WINDOW_SIZE;
int NUM_BOIDS;
int MAX_TIME;
int NUM_FRAMES;

void print_flock(Flock f){//debbuging purpose
  for(int i=0; i<NUM_BOIDS; i++){
    printf("B%d: x:%d, y:%d\n",i, f.flock[i].get_position().x, f.flock[i].get_position().y);
    
  }
}
int main(int argc, char** argv){

//Pobierz ustawienia poczatkowe z wejścia
  if(argc < 5){
    puts("Za mało argumentów");
    puts("boids WINDOW_SIZE NUM_BOIDS MAX_TIME NUM_FRAMES");
    exit(1);
  }else{
    WINDOW_SIZE = atoi(argv[1]);
    NUM_BOIDS = atoi(argv[2]);
    MAX_TIME = atoi(argv[3]);
    NUM_FRAMES = atoi(argv[4]);

    if( WINDOW_SIZE == 0 || NUM_BOIDS == 0 || MAX_TIME == 0 || NUM_FRAMES == 0 ){
      puts("Parametry muszą być liczbami całkowitymi");
      exit(1);
    }
  }

  Flock flock (WINDOW_SIZE, NUM_BOIDS);
  print_flock(flock);
  flock.update_flock();
  printf("Okno ma rozmiar: %dx%d, posiada %d boidów, pracuje max %ds lub aż wygeneruje %d klatek\n",WINDOW_SIZE, WINDOW_SIZE, NUM_BOIDS, MAX_TIME, NUM_FRAMES);
  return 1;
}

