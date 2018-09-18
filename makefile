INCLUDE=-I/home/cao/CAOCCC/DataStructure 
<<<<<<< HEAD
test : C9_2.o
	g++ -g -o test C9_2.o
C9_2.o: C9_2.cpp
	g++ -g $(INCLUDE)-std=c++11 -c C9_2.cpp
clean:
	rm test C9_2.o
=======
test : 564.o
	g++ -g -o test 564.o
564.o: 564.cpp
	g++ -g $(INCLUDE)-std=c++11 -c 564.cpp
clean:
	rm test 564.o
>>>>>>> 2ec94a540cb71c8d5a3ad837be49b17cae8c5415
