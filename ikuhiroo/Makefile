.PHONY: clean
 
a.out: main.o sample.o
	g++ -g3 -O0 -Wall -std=c++11 main.o sample.o
 
main2.o: main.cpp sample.h
	g++ -g3 -O0 -Wall -std=c++11 -c main.cpp
 
beta.o: sample.cpp sample.h
	g++ -g3 -O0 -Wall -std=c++11 -c sample.cpp

clean:
	rm -f a.out sample.o
