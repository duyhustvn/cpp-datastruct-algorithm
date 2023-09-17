# Run test: make -f 04.Makefile test
test:
	gcc -o 04.hamming_distance_test.o 04.hamming_distance_test.c -lcmocka
