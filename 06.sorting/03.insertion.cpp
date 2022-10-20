#include <iostream>

using namespace std;

class Solution
{
    public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] <= arr[j]) {
                    int temp = arr[i];
                    for (int k = i; k > j; k--) {
                        arr[k] = arr[k-1];
                    }
                    arr[j] = temp;
                    break;
                }
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
  s->insertionSort(nums1, n1);
  printArray(nums1, n1);
}
