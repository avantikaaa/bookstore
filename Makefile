CC = g++

main: main.o book.o magazine.o cashier.o customer.o storemanager.o person.o auth.o inventory.o
	${CC} main.o book.o magazine.o cashier.o customer.o storemanager.o person.o auth.o inventory.o -o main

inventory.o: cpp/inventory.cpp headers/inventory.h book.o
	${CC} -c cpp/inventory.cpp

auth.o: cpp/auth.cpp headers/auth.h cashier.o customer.o storemanager.o person.o
	${CC} -c cpp/auth.cpp

book.o: cpp/book.cpp headers/book.h
	${CC} -c cpp/book.cpp

magazine.o: cpp/magazine.cpp headers/magazine.h cpp/book.cpp
	${CC} -c cpp/magazine.cpp

cashier.o: cpp/cashier.cpp headers/cashier.h cpp/person.cpp cpp/inventory.cpp
	${CC} -c cpp/cashier.cpp

customer.o: cpp/customer.cpp headers/customer.h cpp/person.cpp cpp/cashier.cpp
	${CC} -c cpp/customer.cpp

storemanager.o: cpp/storemanager.cpp headers/storemanager.h cpp/person.cpp cpp/inventory.cpp
	${CC} -c cpp/storemanager.cpp

person.o: cpp/person.cpp headers/person.h
	${CC} -c cpp/person.cpp

main.o: cpp/main.cpp cpp/book.cpp cpp/magazine.cpp cpp/cashier.cpp cpp/customer.cpp cpp/storemanager.cpp cpp/person.cpp cpp/auth.cpp cpp/inventory.cpp
	${CC} -c cpp/main.cpp

clean:
	rm -f *.o main