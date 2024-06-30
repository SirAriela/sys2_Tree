#//arielag1998@gmail.com
#//206862666



CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion -pedantic
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99
LDLIBS = -pthread -lsfml-graphics -lsfml-window -lsfml-system

SOURCES = Demo.cpp main.cpp node.cpp tree.cpp mainwindow.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: demo main my_test

demo: Demo.o node.o tree.o mainwindow.o
	$(CXX) $(CXXFLAGS) $^ -o demo $(LDLIBS)

main: main.o node.o tree.o mainwindow.o
	$(CXX) $(CXXFLAGS) $^ -o main $(LDLIBS)

my_test: Dice.o Player.o Map.o Tile.o Deck.o myTest.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o my_test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo 
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./main 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o my_test demo main

.PHONY: all tidy valgrind clean
