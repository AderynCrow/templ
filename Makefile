templ: main.o copy.o templateGetter.o replacer.o
	clang++ main.o copy.o templateGetter.o replacer.o -o templ
main.o: main.cpp
	clang++ -c main.cpp
templateGetter.o: templateGetter.cpp
	clang++ -c templateGetter.cpp
copy.o: copy.cpp
	clang++ -c copy.cpp
replacer.o: replacer.cpp
	clang++ -c replacer.cpp
