test_main : priority_queue.o set.o test.o my_vector.o
	g++ priority_queue.o set.o test.o my_vector.o -o test_main
test.o : test.cpp
	g++ -c test.cpp
priority_queue.o : priority_queue.cpp priority_queue.h
	g++ -c priority_queue.cpp priority_queue.h
set.o : set.cpp set.h
	g++ -c set.cpp set.h
my_vector.o : my_vector.cpp my_vector.h
	g++ -c my_vector.h my_vector.cpp
clean :
	rm *.o
