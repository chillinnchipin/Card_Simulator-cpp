CC := gcc
CXX := g++
CFLAGS :=
CXXFLAGS :=
CPPFLAGS := -c
ARGPARSE_STAMP := .argparse-built

all: cardsim test check

cardsim: deck.o card.o cardsim.o
	$(CXX) $(CXXFLAGS) cardsim.o deck.o card.o -o cardsim

cardsim.o: src/main.cpp
	$(CXX) $(CPPFLAGS) src/main.cpp -o cardsim.o

deck.o: src/include/deck.hpp src/deck.cpp card.o
	$(CXX) $(CPPFLAGS) src/deck.cpp -o deck.o

card.o: src/include/card.hpp src/card.cpp
	$(CXX) $(CPPFLAGS) src/card.cpp -o card.o

test: test/tests.cpp deck.o card.o argparse
	$(CXX) $(CPPFLAGS) test/tests.cpp -o tests.o
	$(CXX) $(CXXFLAGS) tests.o deck.o card.o -o tests -lcunit

check: test
	./tests Automated

$(ARGPARSE_STAMP): src/include/argparse
	cmake -DARGPARSE_BUILD_SAMPLES=on -DARGPARSE_BUILD_TESTS=on -S src/include/argparse/ -B src/include/argparse/build/
	make -C src/include/argparse/build
	./src/include/argparse/build/test/tests
	make -C src/include/argparse/build install
	touch $@

argparse: $(ARGPARSE_STAMP)

clean: 
	rm *.o
