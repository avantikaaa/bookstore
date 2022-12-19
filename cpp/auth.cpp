#include "../headers/auth.h"

using namespace std;

unordered_map<string, string> Auth::customers;
unordered_map<string, string> Auth::cashiers;
unordered_map<string, string> Auth::storemanagers;
unordered_map<string, Customer*> Auth::customers_obj;
unordered_map<string, Cashier*> Auth::cashiers_obj;
unordered_map<string, Storemanager*> Auth::storemanagers_obj;

Customer* Auth::customer_signup(string username, string password){
	if(Auth::customers.find(username) != Auth::customers.end()){
		return NULL;
	}
	Auth::customers[username] = password;
	string name;
	int age;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;

	Customer* customer = new Customer(name, age);
	Auth::customers_obj[username] = customer;
	return customer;
}

Cashier* Auth::cashier_signup(string username, string password){
		if(Auth::cashiers.find(username) != Auth::cashiers.end()){
		return NULL;
	}
	Auth::cashiers[username] = password;
	string name;
	int age;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;

	Cashier* cashier = new Cashier(name, age);
	Auth::cashiers_obj[username] = cashier;
	return cashier;
}

Storemanager* Auth::storemanager_signup(string username, string password){
		if(Auth::storemanagers.find(username) != Auth::storemanagers.end()){
		return NULL;
	}
	Auth::storemanagers[username] = password;
	string name;
	int age;
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter age: ";
	cin >> age;

	Storemanager* storemanager = new Storemanager(name, age);
	Auth::storemanagers_obj[username] = storemanager;
	return storemanager;
}

Customer* Auth::customer_signin(string username, string password){
	if(Auth::customers.find(username) == Auth::customers.end()){
		return NULL;
	}
	if(Auth::customers[username] == password){
		return Auth::customers_obj[username];
	}
	return NULL;
}

Cashier* Auth::cashier_signin(string username, string password){
	if(Auth::cashiers.find(username) == Auth::cashiers.end()){
		return NULL;
	}
	if(Auth::cashiers[username] == password){
		return Auth::cashiers_obj[username];
	}
	return NULL;
}

Storemanager* Auth::storemanager_signin(string username, string password){
	if(Auth::storemanagers.find(username) == Auth::storemanagers.end()){
		return NULL;
	}
	if(Auth::storemanagers[username] == password){
		return Auth::storemanagers_obj[username];
	}
	return NULL;
}