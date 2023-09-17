# Run test: make -f 05.Makefile test
test:
	gcc -o 05.missing_number_test.o 05.missing_number_test.c -lcmocka
