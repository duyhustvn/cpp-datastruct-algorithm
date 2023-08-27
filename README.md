## Requirement 
- google test [http://google.github.io/googletest/][PlDb]

## Run the test 
### C++ with gtest
```
g++ -std=c++14 -lgtest -o hello_test.out hello_test.cpp
```

### C with Cmocka

``` sh
gcc -o hello_test.out hello_test.c -lcmocka
```
