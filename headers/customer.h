#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"
#include "cashier.h"

using namespace std;

class Customer : public Person{
private:
	int custID;
	static int ID;
public:
	Customer();
	Customer(string);
	// Customer(int);
	Customer(string, int);
	int getId();
	int buyBook(string, int);
	int requestPrice(string);
};

#endif