#ifndef TESTING_H_
#define TESTING_H_

#include <iostream>
#include <vector>

using namespace std;

struct TestData {
    vector<int> nums;
    vector<int> expectedResult;
};

struct TestResult {
    int id;
    vector<int> actualResult;
};

void printResult(vector<TestResult>& testResults, vector<TestData>& tests) {
  if (testResults.size() == 0) {
    cout << "All tests passed" << endl;
    return;
  }

  cout << "There are " << testResults.size() << " failed" << endl;

  printf("%10s%20s%20s\n", "ID", "Expected Output", "Actual Output");
  for (auto tr: testResults) {
    int testId = tr.id;

    string expectedResultString = "";
    string actualResultString = "";

    for (auto e: tests[testId].expectedResult) {
      expectedResultString = expectedResultString + to_string(e) + " ";
    }

    for (auto e: tr.actualResult) {
      actualResultString = actualResultString + to_string(e) + " ";
    }


    printf("%10d%20s%20s\n", testId, expectedResultString.c_str(), actualResultString.c_str());

    cout << endl;
  }
}


#endif // TESTING_H_
