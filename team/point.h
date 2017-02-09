#ifndef POINT_H
#define POINT_H


class Point
{
  private:
   int x;
   int y;

  public:
   void display() const;
   Point();
   Point(int x, int y);
   int getX() const { return x; }
   int getY() const { return y; }
   void setX(int x);
   void setY(int y);

};

#endif
