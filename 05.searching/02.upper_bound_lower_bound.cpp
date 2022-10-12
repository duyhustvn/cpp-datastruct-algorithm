#include <iostream>
#include <vector>

using namespace std;

// return index of the first element that greater than the target
// if no element found return the end of vector
int builtInUpperBound(vector<int>& nums, int target) {
  return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int upperBound(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int result = nums.size();
  int mid;
  while (left <= right) {
    mid = (left+right)/2;
    if (nums[mid] > target) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
}

// return index of the first element greater or equal to the target
int builtInLowerBound(vector<int>& nums, int target) {
  return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int lowerBound(vector<int>& nums, int target) {
  int left = 0;
  int right = nums.size() - 1;
  int result = nums.size();
  while (left <= right) {
    int mid = (left + right) / 2;
    if (nums[mid] >= target) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return result;
}

struct TestData {
    vector<int> nums;
    int target;
    int expectedIndex;
};

struct TestResult {
    int id;
    int actualResult;
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
    printf("%10d%20d%20d\n", testId, tests[testId].expectedIndex, tr.actualResult);
  }
}

void testBuiltInUpperBound() {
  vector<TestData> tests{
    {
      {10, 20, 20, 30, 40, 40}, 30, 4 // upper_bound return the iterator to index 4 of the first element (40) that greater than 30
    },
    {
      {10, 20, 20, 30, 40, 40}, 40, 6 // upper_bound there is no element greater than 40 so it return the iterator to the end of vector -> 6
    },
  };


  vector<TestResult> testResults;
  for (int i = 0; i < tests.size(); i++) {
    TestData test = tests[i];
    int actualIndex = builtInUpperBound(test.nums, test.target);

    if (actualIndex != test.expectedIndex) {
      TestResult r {
        i, actualIndex
      };

      testResults.push_back(r);
    }
  }

  printResult(testResults, tests);
}

void testUpperBound() {
  vector<TestData> tests{
    {
      {10, 20, 20, 30, 40, 40}, 30, 4 // upper_bound return the iterator to index 4 of the first element (40) that greater than 30
    },
    {
      {10, 20, 20, 30, 40, 40}, 40, 6 // upper_bound there is no element greater than 40 so it return the iterator to the end of vector -> 6
    },
    {
      {10, 20, 20, 30, 40, 40}, 5, 0 // upper_bound there is no element greater than 40 so it return the iterator to the end of vector -> 6
    },
  };


  vector<TestResult> testResults;
  for (int i = 0; i < tests.size(); i++) {
    TestData test = tests[i];
    int actualIndex = upperBound(test.nums, test.target);

    if (actualIndex != test.expectedIndex) {
      TestResult r {
        i, actualIndex
      };

      testResults.push_back(r);
    }
  }

  printResult(testResults, tests);
}


void testBuiltInLowerBound() {
  vector<TestData> tests{
    {
      {10, 20, 20, 30, 30, 40, 40}, 30, 3
    },
    {
      {10, 20, 20, 30, 40, 40}, 10, 0
    },
    {
      {10, 20, 20, 30, 40, 40}, 15, 1
    },

  };


  vector<TestResult> testResults;
  for (int i = 0; i < tests.size(); i++) {
    TestData test = tests[i];
    int actualIndex = builtInLowerBound(test.nums, test.target);

    if (actualIndex != test.expectedIndex) {
      TestResult r {
        i, actualIndex
      };

      testResults.push_back(r);
    }
  }

  printResult(testResults, tests);
}


void testLowerBound() {
  vector<TestData> tests{
    {
      {10, 20, 20, 30, 30, 40, 40}, 30, 3
    },
    {
      {10, 20, 20, 30, 40, 40}, 10, 0
    },
    {
      {10, 20, 20, 30, 40, 40}, 15, 1
    },
    {
      {10, 20, 20, 30, 40, 40}, 40, 4
    },
    {
      {10, 20, 20, 30, 40, 40}, 45, 6
    },
  };


  vector<TestResult> testResults;
  for (int i = 0; i < tests.size(); i++) {
    TestData test = tests[i];
    int actualIndex = lowerBound(test.nums, test.target);

    if (actualIndex != test.expectedIndex) {
      TestResult r {
        i, actualIndex
      };

      testResults.push_back(r);
    }
  }

  printResult(testResults, tests);
}


int main() {
  cout << "Test Built In Upper Bound" << endl;
  testBuiltInUpperBound();
  cout << endl;

  cout << "Test Built In Lower Bound" << endl;
  testBuiltInLowerBound();
  cout << endl;


  cout << "Test Lower Bound" << endl;
  testLowerBound();
  cout << endl;


  cout << "Test Upper Bound" << endl;
  testUpperBound();
  cout << endl;

  return 0;
}
