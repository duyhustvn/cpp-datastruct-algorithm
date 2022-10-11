#include <iostream>
#include <vector>

using namespace std;

int binarySearchIterative(vector<int> nums, int target) {
    int left = 0;
    int right = nums.size()-1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int binarySearchRecursion(vector<int>& nums, int target, int left, int right) {
    if (left > right) {
        return -1;
    }

    int mid = (left + right) / 2;
    if (nums[mid] == target) {
        return mid;
    }

    if (nums[mid] > target) {
        return binarySearchRecursion(nums, target, left, mid - 1);
    } else {
        return binarySearchRecursion(nums, target, mid + 1, right);
    }
}

int main() {
    struct DataTest {
        vector<int> nums;
        int target;
        int expectedIndex;
    };

    vector<DataTest> tests{
            {
                    {1,2,3,4}, 3, 2
            },
            {
                    {5}, 5, 0
            }
    };

    vector<vector<int>> failedTest; // [testId, actualIndex]
    for (int i = 0; i < tests.size(); i++) {
        DataTest test = tests[i];

//        int actualIndex = binarySearchIterative(test.nums, test.target);
        int actualIndex = binarySearchRecursion(test.nums, test.target, 0, test.nums.size()-1);
        if (actualIndex != test.expectedIndex) {
            vector<int> v{i, actualIndex};
            failedTest.push_back(v);
        }
    }

    if (failedTest.size() == 0) {
        cout << "All test passed" << endl;
        return 0;
    }

    if (failedTest.size() > 0) {
        cout << "There are: " << failedTest.size() << " failed. Those are: " << endl;
    }
    cout << "Id  Expected  Actual" << endl;
    for (auto test: failedTest) {
        cout << test[0] << "    " << tests[test[0]].expectedIndex << "       " << test[1] << endl;
    }
    cout << endl;
}