#include "../headers/customer.h"
#include "../headers/cashier.h"
#include "../headers/storemanager.h"
#include "../headers/inventory.h"
#include "../headers/book.h"
#include "../headers/auth.h"


using namespace std;

int homePage(){
	cout << "What would you like to do:\n1. Sign IN\n2. Sign UP\n0. Exit\nPlease enter one of the above options: ";
	int op;
	cin >> op;
	while(op > 2 || op < 0){
		cout << "Invalid Input.\nWhat would you like to do:\n1. Sign IN\n2. Sign UP\n0. Exit\nPlease enter one of the above options: ";
		cin >> op;
	}
	return op;
}

int getUserTypes(){
	cout << "Who are you?\n1. Customer\n2. Cashier\n3. Store Manager\n0. Go back\nPlease enter one of the above options: ";
	int op;
	cin >> op;
	while(op > 3 || op < 0){
		cout << "Invalid Input.\nWho are you?\n1. Customer\n2. Cashier\n3. Store Manager\n0. Go back\nPlease enter one of the above options: ";
		cin >> op;
	}
	return op;

}


void signinMenu();

void customerOps(Customer* customer){
	cout << "Operation to be performed:\n1. Get Book Price\n2. Buy Book\n0. Go back\nPlease enter one of the above options: ";
	int task;
	cin >> task;
	switch(task){
		case 0:{
			cout << "WARNING: This will log you out. Do you wish to continue(y/n): ";
			char ans;
			warning_cust: cin >> ans;
			if(ans == 'y' || ans == 'Y'){
				return signinMenu();
			}
			else if(ans == 'n' || ans == 'N'){
				return customerOps(customer);
			}
			cout << "Invalid Input. Do you wish to continue(y/n): ";
			goto warning_cust;
		}
		case 1:{
			cout << "Enter book name: ";
			string book;
			cin >> book;
			int price = customer->requestPrice(book);
			if(price == -1){
				cout << "Invalid Title\n";
			}
			else{
				cout << book << " costs Rs." << price << "/-\n";
			}
			break;
		}
		case 2:{
			cout << "Enter book name: ";
			string book;
			cin >> book;
			int quantity;
			cout << "Enter quantity to be bought: ";
			cin >> quantity;
			int cost = customer->buyBook(book, quantity);
			if(cost == -1){
				cout << "Insufficient stock or invalid title.\n";
			}
			else{
				cout << "Your bill for book: " << book << " for quantity: " << quantity << "is Rs." << cost << "/-\n";
			}
			break;
		}
		default:{
			cout << "Invalid Input\n";
			customerOps(customer);
		}
	}
	customerOps(customer);
	return;
}

void cashierOps(Cashier* cashier){
	cout << "Operation to be performed:\n1. Create Bill\n0. Go back\nPlease enter one of the above options: ";
	int task;
	cin >> task;
	switch(task){
		case 0:{
			cout << "WARNING: This will log you out. Do you wish to continue(y/n): ";
			char ans;
			warning_cash: cin >> ans;
			if(ans == 'y' || ans == 'Y'){
				return signinMenu();
			}
			else if(ans == 'n' || ans == 'N'){
				return cashierOps(cashier);
			}
			cout << "Invalid Input. Do you wish to continue(y/n): ";
			goto warning_cash;
		}
		case 1:{
			cout << "Enter book name: ";
			string book;
			cin >> book;
			int quantity;
			cout << "Enter quantity to be bought: ";
			cin >> quantity;
			int cost = Cashier::createBill(book, quantity);
			if(cost == -1){
				cout << "Insufficient stock or invalid title.\n";
			}
			else{
				cout << "Your bill for book: " << book << " for quantity: " << quantity << "is Rs." << cost << "/-\n";
			}
			break;
		}
		default:{
			cout << "Invalid Input\n";
			cashierOps(cashier);
		}
	}
	cashierOps(cashier);
	return;
}

void storemanagerOps(Storemanager* storemanager){
	cout << "Operation to be performed:\n1. Check price of a book.\n2. Update Stock\n0. Go back\nPlease enter one of the above options: ";
	int task;
	cin >> task;
	switch(task){
		case 0:{
			cout << "WARNING: This will log you out. Do you wish to continue(y/n): ";
			char ans;
			warning_store: cin >> ans;
			if(ans == 'y' || ans == 'Y'){
				signinMenu();
				return;
			}
			else if(ans == 'n' || ans == 'N'){
				storemanagerOps(storemanager);
				return;
			}
			cout << "Invalid Input. Do you wish to continue(y/n): ";
			goto warning_store;
		}
		case 1:{
			cout << "Enter book name: ";
			string book;
			cin >> book;
			int price = Storemanager::getPrice(book);
			if(price == -1){
				cout << "Invalid Title\n";
			}
			else{
				cout << book << " costs Rs." << price << "/-\n";
			}
			break;
		}
		case 2:{
			int type;
			addbook: cout << "Enter 1 for book and 2 for magazine: ";
			cin >> type;
			cout << type << "------\n";
			if(type < 1 || type > 2){
				cout << "heheh Invalid input\n";
				goto addbook;
			}
			cout << "Enter book name: ";
			string book, author;
			cin >> book;
			int quantity, price, edition = 1;
			cout << "Enter price: ";
			cin >> price;
			cout << "Enter quantity to be added: ";
			cin >> quantity;

			if(type == 2){
				cout << "Enter edition: ";
				cin >> edition;
			}
			storemanager->updateStock(book, author, price, quantity, type, edition);
			break;
		}
		default:{
			cout << "Invalid Input\n";
			storemanagerOps(storemanager);
		}
	}
	storemanagerOps(storemanager);
	return;
}


int signin(int person, string user, string password){
	switch(person){
		case 0:
			break;
		case 1:{
			// customer;
			Customer* customer = Auth::customer_signin(user, password);
			if(customer == NULL){
				return -1;
			}
			customerOps(customer);
			break;
		}
		case 2:{
			Cashier* cashier = Auth::cashier_signin(user, password);
			if(cashier == NULL){
				return -1;
			}
			cashierOps(cashier);
			break;
		}
		case 3:{
			Storemanager* storemanager = Auth::storemanager_signin(user, password);
			if(storemanager == NULL){
				return -1;
			}
			storemanagerOps(storemanager);
			break;
		}
		default:{
			cout << "Invalid Input\n";
			break;
		}
	}
	return 0;
}

int signup(int task, string user, string password){
	switch(task){
		case 0:
			break;
		case 1:{
			// customer;
			Customer* customer = Auth::customer_signup(user, password);
			if(customer == NULL){
				return -1;
			}
			customerOps(customer);
			break;
		}
		case 2:{
			Cashier* cashier = Auth::cashier_signup(user, password);
			if(cashier == NULL){
				return -1;
			}
			cashierOps(cashier);
			break;
		}
		case 3:{
			Storemanager* storemanager = Auth::storemanager_signup(user, password);
			if(storemanager == NULL){
				return -1;
			}
			storemanagerOps(storemanager);
			break;
		}
		default:{
			cout << "Invalid Input\n";
			break;
		}
	}
	return 0;
}

void signinMenu(){
	int person = getUserTypes();
	string user, password;
	cout << "Enter Username: ";
	cin >> user;
	cout << "Enter Password: ";
	cin >> password;
	while(signin(person, user, password) == -1){
		cout << "Invalid username or password. Please try again.\n";
		cout << "Enter Username: ";
		cin >> user;
		cout << "Enter Password: ";
		cin >> password;
	}
}

void signupMenu(){
	int person = getUserTypes();
	string user, password;
	cout << "Enter Username: ";
	cin >> user;
	cout << "Enter Password: ";
	cin >> password;
	while(signup(person, user, password) == -1){
		cout << "Invalid username or password. Please try again.\n";
		cout << "Enter Username: ";
		cin >> user;
		cout << "Enter Password: ";
		cin >> password;
	}
}

int main(){
	cout << "------------WELCOME------------\n";
	int task = 1;
	while(task){
		task = homePage();
		if(task == 1){
			// sign in
			signinMenu();
		}
		else if(task == 2){
			// sign up
			signupMenu();
		}
	}
	// print main menu

	// logged in user
	// 3 menus: customer, cashier, store manager

	return 0;
}