#include "main.h"

int WINDOW_SIZE;
int NUM_BOIDS;
int MAX_TIME;
int NUM_FRAMES;

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
  Frame frame;
  Boid* boids = flock.get_flock();
  ofstream ofs("frame.xml");
  assert(ofs.good());
  boost::archive::xml_oarchive oa(ofs);
  
  for(int i=0; i<NUM_BOIDS; i++){

    frame.add_point(boids[i].get_position()); 
  }

  for( list<Point2D>::iterator iter=frame.pos.begin(); iter != frame.pos.end(); iter++){
    printf("hop %d\n",(*iter).x);
  }
  oa & BOOST_SERIALIZATION_NVP(frame);

  printf("Okno ma rozmiar: %dx%d, posiada %d boidów, pracuje max %ds lub aż wygeneruje %d klatek\n",WINDOW_SIZE, WINDOW_SIZE, NUM_BOIDS, MAX_TIME, NUM_FRAMES);
  return 1;
}
