#ifndef CIRCLE_H
#define CIRCLE_H

#include "point.h"


class circle : public Point
{
   private:
      float _radius;

   public:
      float getRadius() const {  return _radius; }
      void setRadius(float value) {  _radius = value; }

      void promptForCircle();
      void display() const;
};

#endif

