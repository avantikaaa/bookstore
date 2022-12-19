#ifndef	BOOK_H
#define	BOOK_H

#include<bits/stdc++.h>

using namespace std;

class Book{
private:
	string author;
	string name;
	int price;
public:
	Book();
	Book(string, string, int);
	string getName();
	string getAuthor();
	int getPrice();
};

#endif