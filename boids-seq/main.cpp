#include "main.h"

int WINDOW_SIZE;
int NUM_BOIDS;
int MAX_TIME;
int NUM_FRAMES;

ofstream json;

void print_flock(Flock f){//debbuging purpose
  for(int i=0; i<NUM_BOIDS; i++){
    printf("B%d: x:%d, y:%d\n",i, f.flock[i].get_position().x, f.flock[i].get_position().y);
    
  }
}

void write_frame(Flock *f){
//wspolrzedne x
  json << "\"boids\": {\n \"x\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].get_position().x;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";

//wspolrzedne y
  json << "\"y\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].get_position().y;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";
//sasiedzi
  json << "\"neighbours\": [\n";
  for(int i=0; i<NUM_BOIDS; i++){
    json << "[";
    if( (*f).neighbours[i].empty() == false ){
      for(int j=0; j<(*f).neighbours[i].size(); j++){
        json << (*f).neighbours[i][j];
        if(j< (*f).neighbours[i].size()-1)
          json <<", ";
      }
    }
    json << "],\n";
  }
  json << "],\n},\n";
//forces
  json << "\"forces\": {\n";
//cohesion
  json << "\"cohesion\": {\n";
   //wspolrzedne x
  json << "\"x\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].cohesion_force.x;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";

//wspolrzedne y
  json << "\"y\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].cohesion_force.y;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "]\n}\n";
//separation
  json << "\"separation\": {\n";
   //wspolrzedne x
  json << "\"x\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].separate_force.x;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";

//wspolrzedne y
  json << "\"y\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].separate_force.y;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "]\n}\n";
//alignment
  json << "\"alignment\": {\n";
   //wspolrzedne x
  json << "\"x\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].align_force.x;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";

//wspolrzedne y
  json << "\"y\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].align_force.y;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "]\n}\n";
//velocity
  json << "\"velocity\": {\n";
   //wspolrzedne x
  json << "\"x\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].velocity.x;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "],\n";

//wspolrzedne y
  json << "\"y\": [";
  for(int i=0; i<NUM_BOIDS; i++){
    json << (*f).flock[i].velocity.y;
    if(i< NUM_BOIDS-1)
      json <<", ";
  }
  json << "]\n}\n";
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
  struct timeval start, end;
  double delta = 0;

  json.open ("animation.json");
  json << "{\n \"screen\": {\n \"width\": " << WINDOW_SIZE << ",\n \"height\": " << WINDOW_SIZE << "\n },\n";
  json << "\"boids\": {\n \"count\": " << NUM_BOIDS << ",\n \"influance_range\": 32\n },\n \"frames\": [\n";
  gettimeofday(&start, NULL);
  
  for(int i=0; i<NUM_FRAMES; i++){
    printf("update frame: %d\n", i); 
    flock.update_flock(delta);

    printf("write frame:%d\n", i); 
    write_frame(&flock);
    gettimeofday(&end, NULL);
    if(end.tv_sec - start.tv_sec >= MAX_TIME){
      break;
    }
    delta =(double)1/(double)60; //czas między klatkami jest stały(FPS). I tak nie wyświetlamy ich na bierząco
    
  }
  json.close();
  printf("Okno ma rozmiar: %dx%d, posiada %d boidów, pracuje max %ds lub aż wygeneruje %d klatek\n",WINDOW_SIZE, WINDOW_SIZE, NUM_BOIDS, MAX_TIME, NUM_FRAMES);
  return 1;
}

