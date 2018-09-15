INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C9_2.o
	g++ -g -o test C9_2.o
C9_2.o: C9_2.cpp
	g++ -g $(INCLUDE)-std=c++11 -c C9_2.cpp
clean:
	rm test C9_2.o
