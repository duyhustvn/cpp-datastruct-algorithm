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

  int lomutoPartition(int arr[], int l, int h) {
    int pivot = arr[h];
    int i = l - 1;
    for (int j = l; j <= h-1; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(arr[i], arr[j]);
      }
    }

    swap(arr[i+1], arr[h]);
    return i+1;
  }

  int hoarePartition(int arr[], int l, int h)
  {
    int pivot=arr[l];
    int i=l-1,j=h+1;
    while(true){
      do{
        i++;
      }while(arr[i]<pivot);
      do{
        j--;
      }while(arr[j]>pivot);
      if(i>=j)return j;
      swap(arr[i],arr[j]);
    }
  }

  void quickSortUsingLomutoPartition(int arr[], int l, int h) {
    if (l < h) {
      int pivotIndex = lomutoPartition(arr, l, h);
      quickSortUsingLomutoPartition(arr, l, pivotIndex-1);
      quickSortUsingLomutoPartition(arr, pivotIndex+1, h);
    }
  }

  void quickSortUsingHoarePartition(int arr[], int l, int h) {
    if (l < h) {
      int pivotIndex = hoarePartition(arr, l, h);
      quickSortUsingHoarePartition(arr, l, pivotIndex-1);
      quickSortUsingHoarePartition(arr, pivotIndex, h);
    }
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
  int pivotIndex = s->lomutoPartition(arr1, 0, n1-1);
  cout << "pivot index: " << pivotIndex << endl;
  printArray(arr1, n1);

  cout << "Before quick sort: ";
  int arr2[] = {10, 5, 2, 6, 8, 7, 3, 6, 6};
  int n2 = sizeof(arr2)/sizeof(arr2[0]);
  printArray(arr2, n2);
  s->quickSortUsingLomutoPartition(arr2, 0, n2-1);
  cout << "After quick sort:  ";
  printArray(arr2, n2);

  cout << "Before quick sort: ";
  int arr3[] = {10, 5, 2, 6, 8, 7, 3, 6, 6};
  int n3 = sizeof(arr3)/sizeof(arr3[0]);
  printArray(arr3, n3);
  s->quickSortUsingLomutoPartition(arr3, 0, n3-1);
  cout << "After quick sort:  ";
  printArray(arr3, n3);


  return 0;
}
