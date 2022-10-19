#include <iostream>

using namespace std;

class Solution
{
    public:

    void swap(int nums[], int i, int j) {
      int temp = nums[i];
      nums[i] = nums[j];
      nums[j] = temp;
    }


    //Function to sort the array using bubble sort algorithm.
    void bubbleSort(int nums[], int n)
    {
        for (int i = 0; i < n; i++) {
        bool swapped = false;
        for (int j = 0; j < n-i-1; j++) {
          if (nums[j] > nums[j+1]) {
            swap(nums, j, j+1);
            swapped = true;
          }
        }
        if (!swapped) {
          break;
        }
      }
    }
};

void printArray(int nums[], int n) {
  for (int i = 0; i < n; i++) {
    cout << nums[i] << " ";
  }

  cout << endl;
}

int main() {
  Solution *s = new Solution();
  int nums1[] = {1,3,7,2,6,4,5};
  int n1 = sizeof(nums1)/sizeof(nums1[0]);
  s->bubbleSort(nums1, n1);
  printArray(nums1, n1);
}
