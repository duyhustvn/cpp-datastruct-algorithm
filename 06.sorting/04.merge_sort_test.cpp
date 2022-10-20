#include "testing/testing.h"
#include "04.merge_sort.cpp"

void testMergeSort() {
    vector<TestData> tests{
      {
        {10, 5, 30, 15, 7}, {5, 7, 10, 15, 30}
      },
      {
        {10, 20, 40, 30, 40, 20},  {10, 20, 20, 30, 40, 40}
      },
    };

    vector<TestResult> testResults;
    for (int i = 0; i < tests.size(); i++) {
      TestData test = tests[i];
      int n = test.nums.size();
      mergeSort(test.nums, 0, n-1);

      if (test.nums != test.expectedResult) {
        TestResult r {
          i, test.nums
        };

        testResults.push_back(r);
      }
    }

    printResult(testResults, tests);
}

int main() {
  // vector<int> v1{1, 3, 7};
  // vector<int> v2{2, 3, 5, 6, 7};
  // vector<int> merged1 = merge2SortedVector(v1, v2);
  // printVector(merged1);

  // vector<int> v3{1, 3, 7, 2, 3, 5, 6, 7};
  // merge(v3, 0, 2, v3.size()-1);
  // cout << "v3: ";
  // printVector(v3);
  // cout << endl << endl;


  // vector<int> v4{10,5,30,15,7};
  // mergeSort(v4, 0, v4.size()-1);
  // printVector(v4);

  testMergeSort();

  return 1;
}
