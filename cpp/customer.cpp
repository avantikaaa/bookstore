#include "../headers/customer.h"
#include "../headers/storemanager.h"
using namespace std;

int Customer::ID = 100;

Customer::Customer(string n): Person(n){
	custID = ID;
	ID++;
}

Customer::Customer(): Person(){
	custID = ID;
	ID++;
}

Customer::Customer(string n, int a): Person(n, a){
	custID = ID;
	ID++;
}

int Customer::getId(){
	return custID;
}

int Customer::buyBook(string book, int quantity){
	return Cashier::createBill(book, quantity);
}

int Customer::requestPrice(string book){
	return Storemanager::getPrice(book);
}