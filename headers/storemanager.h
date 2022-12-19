#ifndef STOREMANAGER_H
#define STOREMANAGER_H

#include "person.h"
#include "book.h"
#include "inventory.h"
class Storemanager: public Person{
private:
	int userID;
	static int ID;
public:
	Storemanager();
	Storemanager(string);
	Storemanager(string, int);
	int getId();
	int updateStock(string, string, int, int, int, int);
	static int getPrice(string);
};

#endif