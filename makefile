INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C8_1.o
	g++ -g -o test C8_1.o
C8_1.o: C8_1.cpp
	g++ -g $(INCLUDE)-std=c++11 -c C8_1.cpp
clean:
	rm test C8_1.o
