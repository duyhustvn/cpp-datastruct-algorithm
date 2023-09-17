## Requirement 
- google test [https://github.com/google/googletest/blob/main/googletest/README.md]

## Run the test 
### C++ with gtest
```
g++ -std=c++23 -o hello_test.out hello_test.cpp -lgtest
```

### C with Cmocka

``` sh
gcc -o hello_test.out hello_test.c -lcmocka
```
