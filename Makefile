all: test_DyV

test_DyV.o: test_DyV.cpp DyV.h

test_DyV: test_DyV.o 
	g++ -o test_DyV test_DyV.o 

bin/Mochila: mochila.cpp
	mkdir -p bin
	g++ -o bin/mochila mochila.cpp

clean:
	rm -f *.o test_DyV
	rm -f *.gch test_DyV
	rm -f *.o Monedas
	rm -f *.o Mochila

test: all
	./test_DyV
