INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C7_1.o
	g++ -g -o test C7_1.o
C7_1.o: C7_1.cpp SqStack.h SqQueue.h
	g++ -g $(INCLUDE)-std=c++11 -c C7_1.cpp
clean:
	rm test C7_1.o
