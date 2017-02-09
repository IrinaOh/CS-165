/***********************************************************************
* Program:
*    Checkpoint 02b, Complex Numbers
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

// TODO: Define your Complex struct here
struct Complex
{
	double real;       // a complex number that has a real part
	double imaginary;  // a complex number that has an imaginary part
} ;


void prompt(Complex & x, Complex & y);
Complex addComplex(const Complex & x, const Complex & y, Complex & sum);
void display(Complex sum);

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ************************************************************************/
int main()
{
   // Declare two Complex objects, c1 and c2
   Complex x;
   Complex y;

   // Call your prompt function twice to fill in c1, and c2 
	prompt(x, y);

   // Declare another Complex for the sum
	Complex sum;

   // Call the addComplex function, putting the result in sum;
   addComplex(x, y, sum);
   display(sum);

   return 0;
}

/**********************************************************************
 * Prompt
 * Prompt for the real and imaginary numbers
 ***********************************************************************/
void prompt(Complex & x, Complex & y)
{
      // prompt for the x Complex numbers
      cout << "Real: ";
      cin >> x.real;
      cout << "Imaginary: ";
      cin >> x.imaginary;

      // prompt for the y Complex numbers
      cout << "Real: ";
      cin >> y.real;
      cout << "Imaginary: ";
      cin >> y.imaginary;
   
}

/**********************************************************************
 * Function: addComplex
 * Purpose: Adds two complex numbers together and returns the sum.
 ***********************************************************************/
Complex addComplex(const Complex & x, const Complex & y, Complex & sum)
{
   sum.real = x.real + y.real;
   sum.imaginary = x.imaginary + y.imaginary;

}

/**********************************************************************
 * DISPLAY
 * Display the sum for the user
 **********************************************************************/
void display(Complex sum)
{
   cout << endl;
   cout << "The sum is: ";
   cout << sum.real << " + " << sum.imaginary << "i" << endl;
}





