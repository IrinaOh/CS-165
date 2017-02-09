/**********************************************************************
 * File: ta03.cpp
 * Author: Br. Burton
 *
 * Description: Use this file as a starting point for Team Activity 03.
 *    You do not need to "submit" your code, but rather, answer the
 *    questions in the I-Learn assessment.
 **********************************************************************/

#include <iostream>
#include <string>

#include <fstream> // used for file reading
#include <sstream> // used to parse a line

using namespace std;

/***********************************************************************
 * Struct: Scripture
 * Description: Holds the reference to a scripture (book, chapter, verse
 ***********************************************************************/
struct Access
{
   string userName;
   string fileName;
   long timeStamp;
};

/***********************************************************************
 * Function: display
 * Description: Displays the passed scripture.
 ***********************************************************************/
void display(const Access &x)
{
   cout << x.userName << " ";
   cout << x.fileName << ":";
   cout << x.timeStamp;

}

/***********************************************************************
 * Function: promptFile
 * Description: Gets the file name from the user.
 ***********************************************************************/
string promptFile()
{
   string file;

   cout << "Please enter the name of the file: ";
   cin >> file;

   return file;
}

/***********************************************************************
 * Function: parseLine
 * Description: Fills in the parts of the passed scripture, given
 *  the data found in the provided string.
 ***********************************************************************/
void parseLine(string line, Access & newX)
{
   // You would take this line out before submitting a program...
   //cerr << "Debug message: Trying to parse line: " << line << endl;

   stringstream buffer(line);

   buffer >> newX.timeStamp;

   if (buffer.fail())
   {
      cout << "Error processing line: " << line << endl;
   }

   // Please note that for stretch challenges, you'll need additional checks

   buffer >> newX.fileName;
   if (buffer.fail())
   {
      cout << "Error processing line: " << line << endl;
   }
   buffer >> newX.userName;
   if (buffer.fail())
   {
      cout << "Error processing line: " << line << endl;
   }

}

/***********************************************************************
 * Function: parseFile
 * Description: Processes a file of scripture data line by line. For
 *  each line, it parses into a scripture and displays it.
 ***********************************************************************/
bool parseFile(string file)
{
   // must use .c_str() because fstream can't handle strings
   ifstream fin(file.c_str());

   // ensure the file opened correctly
   if (fin.fail())
   {
      cout << "Error opening file: " << file << endl;
      return false; // FYI, this is an error flag technique...
   }

   string line;

   while (getline(fin, line))
   {
      Access newX;

      // parse the line into the provided scripture struct
      parseLine(line, newX);

      display(newX);
      cout << endl;
   }

   fin.close();
}

/***********************************************************************
 * Function: main
 * Description: The driver for the program.
 ***********************************************************************/
int main()
{
   string file = promptFile();
   parseFile(file);

   return 0;
}
