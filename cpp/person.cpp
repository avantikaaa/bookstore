#include "../headers/person.h"

using namespace std;

Person::Person(){
	;
}

Person::Person(string n){
	name = n;
}

Person::Person(int a){
	age = a;
}

Person::Person(string n, int a){
	name = n;
	age = a;
}

string Person::getName(){
	return name;
}

int Person::getAge(){
	return age;
}
