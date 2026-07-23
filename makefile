CC := gcc
CXX := g++
CFLAGS :=
CXXFLAGS :=
CPPFLAGS := -c

all: cardsim test

cardsim: deck.o card.o cardsim.o
	$(CXX) $(CXXFLAGS) cardsim.o deck.o card.o -o cardsim

cardsim.o: src/main.cpp
	$(CXX) $(CPPFLAGS) src/main.cpp -o cardsim.o

deck.o: headers/deck.hpp src/deck.cpp card.o
	$(CXX) $(CPPFLAGS) src/deck.cpp -o deck.o

card.o: headers/card.hpp src/card.cpp
	$(CXX) $(CPPFLAGS) src/card.cpp -o card.o

test: test/tests.cpp deck.o card.o
	$(CXX) $(CPPFLAGS) test/tests.cpp -o tests.o
	$(CXX) $(CXXFLAGS) tests.o deck.o card.o -o tests -lcunit

clean: 
	rm *.o
