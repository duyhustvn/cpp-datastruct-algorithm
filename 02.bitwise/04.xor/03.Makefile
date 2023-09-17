# Run test: make -f 03.Makefile test
test:
	gcc -o 03.opposite_sign_test.o 03.opposite_sign_test.c -lcmocka
