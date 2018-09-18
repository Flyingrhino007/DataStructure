INCLUDE=-I/home/cao/CAOCCC/DataStructure 
test : 564.o
	g++ -g -o test 564.o
564.o: 564.cpp
	g++ -g $(INCLUDE)-std=c++11 -c 564.cpp
clean:
	rm test 564.o
