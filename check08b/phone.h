/***************
 * phone.h
 ***************/

#ifndef PHONE_H
#define PHONE_H

class Phone
{
private:
	int _area;
	int _prefix;
	int _suffix;

public:
	int getAreaCode()           { return _area;     } 
	int getPrefix()             { return _prefix;   }
	int getSuffix()             { return _suffix;   }

	void setAreaCode(int value) { _area = value;     } 
	void setPrefix(int value)   { _prefix = value;   }
	void setSuffix(int value)   { _suffix = value;   }

	void promptNumber();
	void display();

};

#endif

