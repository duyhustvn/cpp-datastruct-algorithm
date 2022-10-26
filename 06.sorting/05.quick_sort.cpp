#include <iostream>
#include <vector>

using namespace std;

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printVector(vector<int> v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}

class Solution {
  public:
  void naivePartition(int arr[], int n, int l, int h, int targetIndex) {
    int temp[h-l+1];
    int index = 0;
    for (int i = l; i <= h; i++) {
      if (arr[i] < arr[targetIndex]) {
        temp[index] = arr[i];
        index++;
      }
    }

    for (int i = l; i <= h; i++) {
      if (arr[i] == arr[targetIndex]) {
        temp[index] = arr[i];
        index++;
      }
    }

    for (int i = l; i <= h; i++) {
      if (arr[i] > arr[targetIndex]) {
        temp[index] = arr[i];
        index++;
      }
    }


    for (int i = l; i <= h; i++) {
      arr[i] = temp[i-l];
    }
  }

  void lomutoPartition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h-1; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i+1], arr[h]);
  }
};


int main() {
  Solution *s = new Solution();
  int arr[] = {10, 5, 2, 6, 8, 7, 3, 6, 6};
  int n = sizeof(arr)/sizeof(arr[0]);
  s->naivePartition(arr, n, 2, n-1, 3);
  printArray(arr, n);

  int arr1[] = {10, 5, 2, 6, 8, 7, 3, 6, 6};
  int n1 = sizeof(arr1)/sizeof(arr1[0]);
  s->lomutoPartition(arr1, 0, n1-1);
  printArray(arr1, n1);

  return 0;
}
