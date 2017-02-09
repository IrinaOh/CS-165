#include <string>     // need you ask?
#include <sstream>    // convert an integer into text
#include <cassert>    // I feel the need... the need for asserts
#include <time.h>     // for clock


#ifdef __APPLE__
#include <openGL/gl.h>    // Main OpenGL library
#include <GLUT/glut.h>    // Second OpenGL library
#endif // __APPLE__

#ifdef __linux__
#include <GL/gl.h>        // Main OpenGL library
#include <GL/glut.h>      // Second OpenGL library
#endif // __linux__

#ifdef _WIN32
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>         // OpenGL library we copied 
#define _USE_MATH_DEFINES
#include <math.h>
#endif // _WIN32

#include "point.h"
#include "uiDraw.h"

using namespace std;

#define deg2rad(value) ((M_PI / 180) * (value))


void drawLanderFlames(const Point & point, bool bottom, bool left, bool right, rotation)
{
   // simple point
   struct PT
   {
      int x;
      int y;
   };

   rotate(tl, center, rotation);
   rotate(tr, center, rotation);
   rotate(bl, center, rotation);
   rotate(br, center, rotation);

   int iFlame = random(0, 3);  // so the flame flickers
   
   // draw it
   glBegin(GL_LINE_LOOP);
   glColor3f(1.0 /* red % */, 0.0 /* green % */, 0.0 /* blue % */);
   
   // bottom thrust
   if (bottom)
   {
      PT points[3][3] =
      {
         { {-5,  -6}, { 0, -1}, { 3, -10} },
         { {-3,  -6}, {-1, -2}, { 0, -15} },
         { { 2, -12}, { 1,  0}, { 6,  -4} }
      };
      
      glVertex2f(point.getX() - 2, point.getY() + 2);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                   point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 2, point.getY() + 2);
   }

   // right thrust
   if (right)
   {
      PT points[3][3] =
      {
         { {10, 14}, { 8, 12}, {12, 12} },
         { {12, 10}, { 8, 10}, {10,  8} },
         { {14, 11}, {14, 11}, {14, 11} }
      };
      
      glVertex2f(point.getX() + 6, point.getY() + 12);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() + 6, point.getY() + 10);
   }

   // left thrust
   if (left)
   {
      PT points[3][3] =
      {
         { {-10, 14}, { -8, 12}, {-12, 12} },
         { {-12, 10}, { -8, 10}, {-10,  8} },
         { {-14, 11}, {-14, 11}, {-14, 11} }
      };
      
      glVertex2f(point.getX() - 6, point.getY() + 12);
      for (int i = 0; i < 3; i++)
         glVertex2f(point.getX() + points[iFlame][i].x,
                    point.getY() + points[iFlame][i].y);
      glVertex2f(point.getX() - 6, point.getY() + 10);
   }

   glColor3f(1.0 /* red % */, 1.0 /* green % */, 1.0 /* blue % */);
   glEnd();
}

void drawRect(const Point & center, int width, int height, int rotation)
{
   Point tl(false /*check*/); // top left
   Point tr(false /*check*/); // top right 
   Point bl(false /*check*/); // bottom left
   Point br(false /*check*/); // bottom right

   //Top Left point
   tl.setX(center.getX() - (width  / 2));
   tl.setY(center.getY() + (height / 2));

   //Top right point
   tr.setX(center.getX() + (width  / 2));
   tr.setY(center.getY() + (height / 2));

   //Bottom left point
   bl.setX(center.getX() - (width  / 2));
   bl.setY(center.getY() - (height / 2));

   //Bottom right point
   br.setX(center.getX() + (width  / 2));
   br.setY(center.getY() - (height / 2));

   //Rotate all points the given degrees
   rotate(tl, center, rotation);
   rotate(tr, center, rotation);
   rotate(bl, center, rotation);
   rotate(br, center, rotation);

   //Finally draw the rectangle
   glBegin(GL_LINE_STRIP);
   glVertex2f(tl.getX(), tl.getY());
   glVertex2f(tr.getX(), tr.getY());
   glVertex2f(br.getX(), br.getY());
   glVertex2f(bl.getX(), bl.getY());
   glVertex2f(tl.getX(), tl.getY());
   glEnd();
}

/************************************************************************
 * DRAW CIRCLE
 * Draw a circle from a given location (center) of a given size (radius).
 *  INPUT   center   Center of the circle
 *          radius   Size of the circle
 *************************************************************************/
void drawCircle(const Point & center, int radius)
{
   assert(radius > 1.0);
   const double increment = 1.0 / (double)radius;

   // begin drawing
   glBegin(GL_LINE_LOOP);

   // go around the circle
   for (double radians = 0; radians < M_PI * 2.0; radians += increment)
      glVertex2f(center.getX() + (radius * cos(radians)),
                 center.getY() + (radius * sin(radians)));
   
   // complete drawing
   glEnd();   
}