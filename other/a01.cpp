/***********************************************************************
* Program:
*    Assignment 01, Genetic Genealogy
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary:
*    This program will compare DNA of people
*
*    Estimated:  1.0 hrs
*    Actual:     0.5 hrs
*    The most difficult part was the matching DNA
************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int DNA = 10;
void getDNAsequence(char myDNA[]);
void getNumRelatives(int &relatives);
void getRelativesNames(int relatives, string relativeName[]);
void getRelativesDNA(int relatives, string relativeName[],
                     char relativeDNA[][DNA]);
void computeMatch(int relatives, char myDNA[], char relativeDNA[][DNA],
                  string relativeName[]);



/**********************************************************************
 * This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int relatives = 0;
   char myDNA[256];
   getDNAsequence(myDNA);
   getNumRelatives(relatives);
   string relativeName[relatives];
   char relativeDNA[relatives][DNA];
   getRelativesNames(relatives, relativeName);
   getRelativesDNA(relatives, relativeName, relativeDNA);
   computeMatch(relatives, myDNA, relativeDNA, relativeName);

   return 0;
}

/**********************************************************************
 * This function will get the DNA sequence of the user
 ***********************************************************************/
void getDNAsequence(char myDNA[])
{
  cout << "Enter your DNA sequence: ";
   cin >> myDNA;
}

/**********************************************************************
 * This function will get the number of relatives
 ***********************************************************************/
void getNumRelatives(int &relatives)
{
   cout << "Enter the number of potential relatives: ";
   cin >> relatives;
   cout << endl;
}

/**********************************************************************
 * This function will get the relatives Names
 ***********************************************************************/
void getRelativesNames(int relatives, string relativeName[])
{
   for (int i = 0; i < relatives; i++)
   {
      cout << "Please enter the name of relative #" << i + 1 << ": ";
      cin >> relativeName[i];
      cin.clear();
      cin.ignore(80, '\n');
   }

   cout << '\n';
}

/**********************************************************************
 * This function will get the relatives DNA
 ***********************************************************************/
void getRelativesDNA(int relatives, string relativeName[],
                     char relativeDNA[][DNA])
{
   for (int i = 0; i < relatives; i++)
   {
      cout << "Please enter the DNA sequence for " << relativeName[i] << ": ";
      cin >> relativeDNA[i];
      cin.clear();
      cin.ignore(80, '\n');
   }
   cout << '\n';
}

/**********************************************************************
 * This function will compute the percentage match between DNA
 ***********************************************************************/
void computeMatch(int relatives, char myDNA[],
                  char relativeDNA[][DNA], string relativeName[])
{
   int count = 0;
   // for each person
   for (int i = 0; i < relatives; i++)
   {
      count = 0;

      // count the DNA matches for that person
      for (int j = 0; j < DNA; j++)
      {
         if (myDNA[j] == relativeDNA[i][j])
            count++;
      }
      cout << "Percent match for " << relativeName[i] << ": "
           << count * 10 << "%" <<  endl;
   }
}
