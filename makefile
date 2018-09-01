INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C6_1.o
	g++ -g -o test C6_1.o
C6_1.o: C6_1.cpp SqStack.h
	g++ -g $(INCLUDE)-std=c++11 -c C6_1.cpp
clean:
	rm test C6_1.o
