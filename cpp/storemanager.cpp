#include "../headers/storemanager.h"
#include "../headers/inventory.h"
using namespace std;

int Storemanager::ID = 100;
Storemanager::Storemanager(string n): Person(n){
	userID = ID;
	ID++;
}

Storemanager::Storemanager(): Person(){
	userID = ID;
	ID++;
}

Storemanager::Storemanager(string n, int a): Person(n, a){
	userID = ID;
	ID++;
}

int Storemanager::getId(){
	return userID;
}

int Storemanager::updateStock(string book_name, string author, int price, int quantity, int type, int edition){
	if(type == 1){
		Book *book = new Book(author, book_name, price);
		Inventory::addStock(book, quantity);
	}
	else if(type ==2){
		// magazine;
		Book *book = new Magazine(author, book_name, price, edition);
		Inventory::addStock(book, quantity);
	}
	else{
		return -1;
	}
	return 0;
}

int Storemanager::getPrice(string book_name){
	Book* book = Inventory::getBook(book_name);
	if(book == NULL)
		return -1;
	return book->getPrice();
}