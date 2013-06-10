#include "Structures.h"
 
  Point2D::Point2D(double a, double b)
  {
    x = a;
    y = b;
  }

  Vector2D::Vector2D(float a, float b)
  {
    x = a;
    y = b;
  }

  float Vector2D::get_angle()
  { //v2 = {1,0}
    //angle(v1, v2) = acos( (v1x * v2x + v1y * v2y) / (sqrt(v1x^2+v1y^2) * sqrt(v2x^2+v2y^2)) )
    return acos( x/(sqrt(x*x+y*y)) );
  }

  void Frame::add_point(Point2D point)
  {
      positions.push_back(point);
      separations.push_back(Vector2D(0,0));
      alignments.push_back(Vector2D(0,0));
      cohesions.push_back(Vector2D(0,0));
  }

  void Frame::add_point()
  {
      positions.push_back(Point2D(0,0));
      separations.push_back(Vector2D(0,0));
      alignments.push_back(Vector2D(0,0));
      cohesions.push_back(Vector2D(0,0));
  }

