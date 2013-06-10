#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include <cmath>

using namespace std;

class Vector2D
{

public:
  float x;
  float y;
  inline float get_length() { return sqrt(x*x+y*y); };
  float get_angle(); 
  Vector2D(){};
  Vector2D(float , float);
  Vector2D operator+ (Vector2D &addend) {return Vector2D(x+addend.x, y+addend.y); };  //yup, lubimy przeciążać te oczywiste operatory
};

class Point2D
{
public:
  double x;
  double y;
  Point2D(){};
  Point2D(double , double );
  Point2D operator+ (Point2D &addend) {return Point2D(x+addend.x, y+addend.y); };  
};

class Frame
{
public:
  list<Point2D>positions;
  list<Vector2D>separations;
  list<Vector2D>alignments;
  list<Vector2D>cohesions;
  Frame(){};
  void add_point(Point2D);
  void add_point();
  void set_positions(list<Point2D> l){positions = l;};
  void set_separations(list<Vector2D> l){separations = l;};
  void set_alignments(list<Vector2D> l){alignments = l;};
  void set_cohesions(list<Vector2D> l){cohesions = l;};
};
#endif
