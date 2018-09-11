INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : C8_2.o
	g++ -g -o test C8_2.o
C8_2.o: C8_2.cpp
	g++ -g $(INCLUDE)-std=c++11 -c C8_2.cpp
clean:
	rm test C8_2.o
