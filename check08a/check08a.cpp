/***********************************************************************
* Program:
*    Checkpoint 08a, Inheritance
*    Brother Falin, CS165
* Author:
*    Anderson Erichsen Fagundes
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
	string _title;
	string _author;
	int _publicationYear;

public:
	void promptBookInfo();
	void displayBookInfo();

	string getTitle() const { return _title; }
	void setTitle(string value) { _title = value; }

	string getAuthor() const { return _author; }
	void setAuthor(string value) { _author = value; }

	int getPublicationYear() const { return _publicationYear; }
	void setublicationYear(int value) { _publicationYear = value; }
};

class TextBook : public Book
{
private:
	string _subject;

public:
	string getSubject() const { return _subject; }
	void setSubject(string value) { _subject = value; }

	void promptSubject();
	void displaySubject();
};

class PictureBook : public Book
{
private:
	string _illustrator;

public:
	string getIllustrator() const { return _illustrator; }
	void setIllustrator(string value) { _illustrator = value; }

	void promptIllustrator();
	void displayIllustrator();
};


/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{  
	// create the objects
	Book book;
	TextBook textBook;
	PictureBook pictureBook;

	// call the functions for each object
	book.promptBookInfo();
	book.displayBookInfo();


	textBook.promptBookInfo();
	textBook.promptSubject();

	//cin.ignore();
	
	textBook.displayBookInfo();
	

	textBook.displaySubject();
	
	//cin.ignore();

	pictureBook.promptBookInfo();
	pictureBook.promptIllustrator();
	pictureBook.displayBookInfo();
	pictureBook.displayIllustrator();

   return 0;
}


void Book::promptBookInfo()
{
	cout << "Title: ";
	getline(cin, _title);

	//cin.ignore(80, '\n');
	//cin.clear();

	cout << "Author: ";
	getline(cin, _author);

	//cin.ignore(80, '\n');
	//cin.clear();

	cout << "Publication Year: ";
	cin >> _publicationYear;
	//cin.ignore();
	cin.ignore();

	cin.clear();
	
	}

void Book::displayBookInfo()
{
	cout << endl;
	cout << _title << " (" << _publicationYear << ") by " << _author << endl;
	//cin.ignore();
	cout << endl;
}

void TextBook::promptSubject()
{
	//cin.ignore(80, '\n');
	cout << "Subject: ";
	cin.ignore(80, '\n');
	getline(cin, _subject);
	cin.clear();
	//cin.ignore(80, '\n');

}

void TextBook::displaySubject()
{
	cin.ignore();
	cout << endl;
	cout << "Subject: " << _subject << endl;
	//cin.ignore();

	cout << "oi";
}

void PictureBook::promptIllustrator()
{
	cout << "Illustrator: ";
	getline(cin, _illustrator);
	cout << endl;
}

void PictureBook::displayIllustrator()
{
	cout << "Illustrated by " << _illustrator << endl;	
}