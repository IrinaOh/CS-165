// course.cpp

#include "course.h"
#include <string>
#include <iostream>
using namespace std;

Course::Course(int size)
{
      this->size = size;
      classList = new Student[size];
}

Course::~Course() 
{
    delete [] classList;
    classList = NULL;
    std::cout << "Cleaning up course: " << getName() << std::endl;
}

Student Course::getStudent(int index) const
{
  return classList[index]; 
  
}

Course& Course::operator = (const Course &course)
{

   if (classList != NULL)
       delete [] classList;   
    size = course.size;
    classList = new Student[size];
    for (int i = 0; i < size; i++)
       classList[i] = course.classList[i];
     return *this; 
}

Course::Course(const Course & course)
   {
      size = course.size;
      classList = new Student[size];
      for (int i = 0; i < size; i++)
         classList[i] = course.classList[i];
   }

void Course::setStudent(int index, const Student & student)
{
	classList[index] = student;
}

void Course::displayList() const
{
   cout << "Class list for course: " << name << endl;

   for (int i = 0; i < size; i++)
   {
      classList[i].display();
   }
}

