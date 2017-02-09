/*******************
 * NumberList class
 *******************/
#ifndef NUMBER_LIST_H
#define NUMBER_LIST_H

#include <iostream>

class NumberList
{
private:
   int size;
   int *array;

public:
   NumberList()
   {
      size = 0;
      array = NULL;
   }

   NumberList(int num)
   {
      size = num;
      array = new int[num];
   }
   
   NumberList(const NumberList &list)
   {
      size = list.size;
      array = new int[size];
      for (int i = 0; i < size; i++)
         array[i] = list.array[i];
   }
   
   ~NumberList() //destructor from part a
   {
      delete [] array;
      array = NULL;
      std::cout << "Freeing memory\n";
   }

   NumberList & operator = (const NumberList &list)
   {

      if (array != NULL)
         delete [] array;   
      size = list.size;
      array = new int[size];
      for (int i = 0; i < size; i++)
         array[i] = list.array[i];

      return *this; //need to return a pointer here
   }

   int getNumber(int index) const;
   void setNumber(int index, int value);
      void displayList() const;

};

#endif
