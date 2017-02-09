/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics  
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
#include <sstream>
using namespace std;


/**********************************************************************
 * Struct for an Access Record that contains a username, a filename and
 * a long
 ***********************************************************************/
struct Access
{
   string userName;
   string fileName;
   long long timeStamp;
};


void getFilename(char filename[]);
void getStartTime(long& start);
void getEndTime(long& end);
void parseFile(char filename[], int& i, Access x[]);
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
   
   parseFile(filename, i, x);

   cout << endl; // to match testBed

   getStartTime(start);

   getEndTime(end);

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

/***********************************************************************
 * Function: parseLine
 * Description: Fills in the parts of the passed file, given
 *  the data found in the provided string.
 ***********************************************************************/
void parseLine(string line, Access x[], int& i)
{

   stringstream buffer(line);
   bool success = true;
   buffer >> x[i].fileName;
   try
   {
      if (buffer.fail())
      {
         success = false;
         throw "Error parsing line: ";
      }
      buffer >> x[i].userName;
      if (buffer.fail())
      {
         success = false; 
         throw "Error parsing line: ";
      }
      buffer >> x[i].timeStamp;
      
      if (buffer.fail() || x[i].timeStamp < 1000000000 
          || x[i].timeStamp > 10000000000)
      {
         success = false;
         throw "Error parsing line: ";
      }
   }
   catch (const char * message)
   {
      cout << message << line << endl;
   }
   
   i++;
   
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

/**********************************************************************
 * This function will read the file
 ***********************************************************************/
void parseFile(char filename[], int& i, Access x[])
{
   string line;
   // read the file
   ifstream fin(filename); 

   // check for error
   if (fin.fail())
   {
      cout << "Error opening file " << filename << endl;
      return;
   }
   i = 0;
   while (getline(fin, line))
   {
      parseLine(line, x, i);
   }
  
   fin.close();
   
}

