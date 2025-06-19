main: main.o copy.o
	clang++ main.o copy.o
main.o: main.cpp
	clang++ -c main.cpp
copy.o: copy.cpp
	clang++ -c copy.cpp
