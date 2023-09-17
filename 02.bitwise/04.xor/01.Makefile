# Run test: make -f 01.Makefile test
# ./01.swap_2_number_test.o
test:
	gcc -o 01.swap_2_number_test.o 01.swap_2_number_test.c -lcmocka
