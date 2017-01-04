all: bsApp

bsApp: BankSimApp.o PQueue.o Node.o Queue.o Event.o EmptyDataCollectionException.o
	g++ -o bsApp BankSimApp.o PQueue.o Node.o Queue.o Event.o EmptyDataCollectionException.o -std=gnu++11

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

BankSimApp.o: BankSimApp.cpp PQueue.h Node.h Queue.h Event.h EmptyDataCollectionException.h
	g++ -c BankSimApp.cpp -std=gnu++11

PQueue.o: PQueue.cpp PQueue.h Node.h Event.h EmptyDataCollectionException.h
	g++ -c PQueue.cpp -std=gnu++11

Node.o: Node.cpp Node.h Event.h
	g++ -c Node.cpp -std=gnu++11
	
Queue.o: Queue.cpp Queue.h Event.h EmptyDataCollectionException.h
	g++ -c Queue.cpp -std=gnu++11

Event.o: Event.cpp Event.h
	g++ -c Event.cpp -std=gnu++11

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp -std=gnu++11

clean:
	rm -f bsApp *.o
