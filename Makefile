FLAGS = -Wall -Werror -Wextra -std=c++0x

debug: FLAGS += -g
debug: all

Catalog.o: Catalog.h Catalog.cpp Product.h
	g++ $(FLAGS) -c Catalog.cpp -o Catalog.o

ShoppingCart.o: ShoppingCart.h ShoppingCart.cpp
	g++ $(FLAGS) -c ShoppingCart.cpp -o ShoppingCart.o
  
all: Catalog.o ShoppingCart.o main.cpp
	g++ $(FLAGS) main.cpp Catalog.o ShoppingCart.o -o main

clean:
	rm -f *.o main