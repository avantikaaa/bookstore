#include "../headers/book.h"

using namespace std;

Book::Book(){;}

Book::Book(string auth, string name, int cost){
	author = auth;
	this->name = name;
	price = cost;
}

string Book::getName(){
	return name;
}

string Book::getAuthor(){
	return author;
}

int Book::getPrice(){
	return price;
}