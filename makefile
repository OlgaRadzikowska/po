rcMatrix: rcMatrix.o
	g++ -g -Wall -pedantic $^ -o $@

rcMatrix.o: test_matrix.cpp rcMatrix.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm rcMatrix.o rcMatrix
