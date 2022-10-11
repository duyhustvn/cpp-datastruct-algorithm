#include <iostream>
#include <vector>

using namespace std;

class Subsets {
 public:

  // Depth first search
  void method1(int i, vector<int>& nums, vector<int> curSubset, vector<vector<int>>& subsets) {
    if (i == nums.size()) {
      subsets.push_back(curSubset);
      return;
    }

    // not add current element to curSubset
    method1(i+1, nums, curSubset, subsets);

    curSubset.push_back(nums[i]);
    method1(i+1, nums, curSubset, subsets);
  }

  // Breath first search
  void method2(vector<int>& nums, vector<vector<int>>& subsets) {
    // start with empty subset
    subsets.push_back(vector<int>());

    for (auto curNumber: nums) {
      // take all existing subsets and insert the current number in them to create new subsets
      int n = subsets.size();
      for (int i = 0; i < n; i++) {
        // create new subset from the existing subset and insert the current element to it
        vector<int> set(subsets[i]);
        set.push_back(curNumber);
        subsets.push_back(set);
      }
    }
  }

  void method3(int index, vector<int>& nums, vector<int> curSubset, vector<vector<int>>& subsets) {
    subsets.push_back(curSubset);

    for (int i = index; i < nums.size(); i++) {
      curSubset.push_back(nums[i]);
      method3(i+1, nums, curSubset, subsets);
      curSubset.pop_back();
    }
  }

  vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;

    vector<int> curSubset;

    //method1(0, nums, curSubset, subsets);
    // method2(nums, subsets);
    method3(0, nums, curSubset, subsets);

    return subsets;
  }
};

int main(int argc, char* argv[]) {
  Subsets* s = new Subsets();

  vector<int> v1{1, 2, 3};

  vector<vector<int>> result = s->findSubsets(v1);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vector<int> v2{1,5,3};
  result = s->findSubsets(v2);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
