# Run test: make -f 02.Makefile test
# ./02.count_set_bit_test.o
test:
	gcc -o 02.count_set_bit_test.o 02.count_set_bit_test.c -lcmocka -lm
