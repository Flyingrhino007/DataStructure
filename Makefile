INCLUDE=-I/home/cao/CAOCCC/Leetcode 
test : tttt.o
	g++ -g -o test tttt.o
tttt.o: tttt.cpp
	g++ -g $(INCLUDE)-std=c++11 -c tttt.cpp
clean:
	rm test tttt.o
