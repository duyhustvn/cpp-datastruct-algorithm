# Run test: make -f 02.Makefile test
test:
	gcc -o 02.odd_occurence_test.o 02.odd_occurence_test.c -lcmocka
