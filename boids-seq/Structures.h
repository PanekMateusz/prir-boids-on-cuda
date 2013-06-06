#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include <boost/serialization/list.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <cmath>

using namespace std;

class Vector2D
{
private:
  friend class boost::serialization::access;
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(x)
       & BOOST_SERIALIZATION_NVP(y);
  }

public:
  float x;
  float y;
  inline float getLength() { return sqrt(x*x+y*y); };
  float getAngle(); 
  Vector2D(){};
  Vector2D(float , float);
  Vector2D operator+ (Vector2D &addend) {return Vector2D(x+addend.x, y+addend.y); };  //yup, lubimy przeciążać te oczywiste operatory
};

class Point2D
{
private:
  friend class boost::serialization::access;
  template<class Archive> 
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(x)
       & BOOST_SERIALIZATION_NVP(y);
  }

public:
  int x;
  int y;
  Point2D(){};
  Point2D(int , int );
};

class Frame
{
private:
  friend class boost::serialization::access;  
  template<class Archive>
  void serialize(Archive & ar, const unsigned int version)
  {
    ar & BOOST_SERIALIZATION_NVP(pos);
  }

public:
  list<Point2D>positions;
  list<Vector2D>separetions;
  list<Vector2D>alignments;
  list<Vector2D>cohesions;
  Frame(){};
  void addPoint(Point2D);
  void addPoint();
};
#endif
