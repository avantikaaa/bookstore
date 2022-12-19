#ifndef CASHIER_H
#define CASHIER_H

#include "person.h"
#include "book.h"
#include "inventory.h"

class Cashier: public Person{
private:
	int userID;
	static int ID;
public:
	Cashier();
	Cashier(string);
	Cashier(string, int);
	int getId();
	static int createBill(string, int);
};

#endif