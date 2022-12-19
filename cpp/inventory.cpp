#include "../headers/inventory.h"

using namespace std;

unordered_map<Book*, int> Inventory::stock;
unordered_map<string, Book*> Inventory::bookItem;

void Inventory::addStock(Book *book, int quantity){
	if(stock.find(book) == stock.end()){
		stock[book] = 0;
		bookItem[book->getName()] = book;
	}
	stock[book] += quantity;
}

bool Inventory::sellBooks(Book *book, int quantity){
	if(stock.find(book) == stock.end() || stock[book] < quantity){
		return false;
	}

	stock[book] -= quantity;
	return true;
}

Book* Inventory::getBook(string name){
	if(bookItem.find(name) == bookItem.end())
		return NULL;
	return bookItem[name];
}

int Inventory::test(){
	cout << "it works?.\n";
	return 0;
}