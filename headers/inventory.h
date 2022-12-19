#ifndef INVENTORY_H
#define INVENTORY_H

#include <bits/stdc++.h>
#include "book.h"
#include "magazine.h"

using namespace std;

class Inventory{
private:
	static unordered_map<Book*, int> stock;
	static unordered_map<string, Book*> bookItem;
public:
	static void addStock(Book*, int);
	static bool sellBooks(Book*, int);
	static Book* getBook(string);
	static int test();
};

#endif