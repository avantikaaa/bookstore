#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "book.h"

// class Date{
// public:
// 	int day;
// 	int month;
// 	int year;
// 	string getDate();
// };

class Magazine: public Book{
private:
	// Date date_release;
	int edition;
public:
	Magazine();
	Magazine(string, string, int, int);
	int getEdition();
};

#endif