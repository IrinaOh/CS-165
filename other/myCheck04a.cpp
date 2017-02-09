/***********************************************************************
* Program:
* Checkpoint 04a, Class
* Brother Falin, CS165
* Author:
* Anderson Erichsen Fagundes  
* Summary: 
*  
************************************************************************/
#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * 1- Create a class called "Book" with the following private data members:
 *   - title
 *   - author
 * 2- Add a prompt method (function) to your class, which asks the user to 
 *    enter a title and an author and stores them in the member variables. 
 *    (Don't forget to use getline here to allow for spaces.)
 * 3- Add a display method to your class, which displays the member variables 
 *    in the format: "the book title" by the author.
 * 4- For this assignment, you may use only one file and put the class 
 *    and it's methods (functions) at the top of the file.
 * 5- Have main:
 *   - Create a Book object.
 *   - Call its prompt method.
 *   - Call its display method.
 ***********************************************************************/

/**********************************************************************
 * Time
 * A class to keep track of books
 ***********************************************************************/
class Book
{
public:
	string promptTitle();
	string promptAuthor();
	void display();
};

/**********************************************************************
 * Book :: promptBook
 * It will prompt for the book title and the author
 ***********************************************************************/
string Book :: promptTitle()
{
	string title;
	cout << "Title: ";
	getline(cin, title);

	return title;
}

 /**********************************************************************
 * 
 ***********************************************************************/
string Book :: promptAuthor()
{
    string author;   
    cout << "Author: ";
	getline(cin, author);
	return author;
}

/**********************************************************************
 * 
 ***********************************************************************/
void Book :: display()
{
	string title = promptTitle(); 
	string author = promptAuthor();
	cout << "\"" << title << "\" " << "by " << author << endl; 
}

/**********************************************************************
 * Main will call the other functions
 ***********************************************************************/
int main()
{
   Book book;
   book.display();
      
   return 0;
}

