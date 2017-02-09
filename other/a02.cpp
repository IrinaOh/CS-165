/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics  
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Write a program to scan through that log to identify users 
*    who accessed files in a particular window of time.
*
*    Estimated:  0.0 hrs   
*    Actual:     2.5 hrs
*      THe most difficult part was passing the correct parameters 
************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


/**********************************************************************
 * Struct for an Access Record that contains a username, a filename and
 * a long
 ***********************************************************************/
struct Access
{
   string userName;
   string fileName;
   long timeStamp;
};


void getFilename(char filename[]);
void getStartTime(long& start);
void getEndTime(long& end);
void readFile(char filename[], int& i, Access x[]);
void displayResults(int& i, long& start, long& end, Access x[]);

/**********************************************************************
 * Main will call the other functions
 ***********************************************************************/
int main()
{
   // store my variables here
   char filename[256];
   long start;
   long end;
   int i = 0;
   Access x[256]; // Access comes from the struct

   // call my functions here
   getFilename(filename);
      
   getStartTime(start);

   getEndTime(end);
   
   readFile(filename, i, x);

   displayResults(i, start, end, x);
   
   return 0;

}

/**********************************************************************
 * This function will get the name of the file
 ***********************************************************************/
void getFilename(char filename[])
{
   cout << "Enter the access record file: ";
   cin >> filename;
   cout << "\n";
}

/**********************************************************************
 * This function will get the start time
 ***********************************************************************/
void getStartTime(long& start)
{
   cout << "Enter the start time: ";
   cin >> start;
}

/**********************************************************************
 * This function will get the end time
 ***********************************************************************/
void getEndTime(long& end)
{
   cout << "Enter the end time: ";
   cin >> end;
}

/**********************************************************************
 * This function will read the file
 ***********************************************************************/
void readFile(char filename[], int& i, Access x[])
{
   // read the file
   ifstream fin(filename); 

   // check for error
   if (fin.fail())
   {
      cout << "Error opening file " << filename << endl;
      return;
   }
   
   // store the file into the struct
   while (fin >> x[i].fileName >> x[i].userName >> x[i].timeStamp) 
   {
      i++;
   }
   
   //close the file
   fin.close();
   
}

/**********************************************************************
 * This function will display the data asked for
 ***********************************************************************/
void displayResults(int& i, long& start, long& end, Access x[])
{

   cout << endl; 
   cout << "The following records match your criteria:\n";
   cout << endl;

   cout << "      Timestamp                File                User\n";
   cout << "--------------- ------------------- -------------------\n";
   
   // display only the data asked for
   for (int j = 0; j < i; j++)
      if (x[j].timeStamp >= start && x[j].timeStamp <= end) 
      {
         cout << setw(15) << x[j].timeStamp << setw(20) 
              << x[j].fileName << setw(20) << x[j].userName << endl;
      }

   cout << "End of records\n";

}


