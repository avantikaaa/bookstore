#include "../headers/cashier.h"
// #include "../headers/inventory.h"
using namespace std;

Cashier::Cashier(string n): Person(n){
	userID = ID;
	ID++;
}

int Cashier::ID = 100;

Cashier::Cashier(): Person(){
	userID = ID;
	ID++;
}

Cashier::Cashier(string n, int a): Person(n, a){
	userID = ID;
	ID++;
}

int Cashier::getId(){
	return userID;
}

int Cashier::createBill(string book_name, int quantity){
	Book* book = Inventory::getBook(book_name);
	if(!book){
		return -1;
	}
	if(Inventory::sellBooks(book, quantity)){
		return book->getPrice() * quantity;
	}
	return -1;
}