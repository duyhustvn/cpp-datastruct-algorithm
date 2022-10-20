#include <iostream>

using namespace std;

class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
       for (int i = 0; i < n; i++) {
        int min = arr[i];
        int minIndex = i;

        for (int j = i; j < n; j++) {
          if (arr[j] < min) {
            min = arr[j];
            minIndex = j;
          }
        }

        if (minIndex != i) {
          swap(arr[i], arr[minIndex]);
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
  s->selectionSort(nums1, n1);
  printArray(nums1, n1);
}
