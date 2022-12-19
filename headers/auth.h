#ifndef AUTH_H
#define AUTH_H

#include "customer.h"
#include "cashier.h"
#include "storemanager.h"
#include <bits/stdc++.h>
using namespace std;

class Auth{
private:
	static unordered_map<string, string> customers;
	static unordered_map<string, string> cashiers;
	static unordered_map<string, string> storemanagers;

	static unordered_map<string, Customer*> customers_obj;
	static unordered_map<string, Cashier*> cashiers_obj;
	static unordered_map<string, Storemanager*> storemanagers_obj;

public:
	static Customer* customer_signup(string, string);
	static Cashier* cashier_signup(string, string);
	static Storemanager* storemanager_signup(string, string);
	static Customer* customer_signin(string, string);
	static Cashier* cashier_signin(string, string);
	static Storemanager* storemanager_signin(string, string);
};

#endif // AUTH_H