INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C7_2.o
	g++ -g -o test C7_2.o
C7_2.o: C7_2.cpp SqStack.h SqQueue.h
	g++ -g $(INCLUDE)-std=c++11 -c C7_2.cpp
clean:
	rm test C7_2.o
