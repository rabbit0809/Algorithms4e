.PHONY: sorting_lib

clean:
	rm driver.o Sorting/sorting_algorithms.o sorting_test

sorting_test:	driver.cc sorting_lib
	g++-12 -c driver.cc -o driver.o
	g++-12 driver.o Sorting/sorting_algorithms.o -o sorting_test

sorting_lib:	Sorting
	cd Sorting && make all
