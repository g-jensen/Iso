SFML_LIB=-lsfml-graphics -lsfml-window -lsfml-system

all: run

run: clean link
	./main

spec: clean spec-link
	./specc.out

clean: 
	rm -f *.o
	rm -f main
	rm -f specc.out

link: compile
	g++ *.o -o main ${SFML_LIB}

compile:
	g++ -c main.cpp
	g++ -c src/*.cpp

clean-spec:
	rm -f specc.o
	rm -f *_spec.o

spec-link: spec-compile
	g++ *.o -o specc.out ${SFML_LIB}

spec-compile:
	g++ -c src/*.cpp
	g++ -c specc/src/specc.c
	g++ -c specc/*_spec.cpp