#include "../headers/magazine.h"

using namespace std;

Magazine::Magazine(): Book(){;}

Magazine::Magazine(string auth, string name, int cost, int edi): Book(auth, name, cost){
	edition = edi;
}

int Magazine::getEdition(){
	return edition;
}
