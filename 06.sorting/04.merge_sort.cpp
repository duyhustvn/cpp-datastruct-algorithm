#include <iostream>
#include <vector>

using namespace std;

vector<int> merge2SortedVector(vector<int> v1, vector<int> v2) {
  int i = 0, j = 0;
  vector<int> result;
  while (i < v1.size() && j < v2.size()) {
    if (v1[i] <= v2[j]) {
      result.push_back(v1[i]);
      i++;
    } else {
      result.push_back(v2[j]);
      j++;
    }
  }

  while (i < v1.size()) {
    result.push_back(v1[i]);
    i++;
  }

  while (j < v2.size()) {
    result.push_back(v2[j]);
    j++;
  }
  return result;
}

void printVector(const vector<int> v) {
  for (auto e: v) {
    cout << e << " ";
  }
  cout << endl;
}

void merge(vector<int> &v, int low, int mid, int high) {

  vector<int> v1(v.begin() + low, v.begin() + mid + 1);
  vector<int> v2(v.begin() + mid + 1, v.begin() + high + 1);

  vector<int> result = merge2SortedVector(v1, v2);

  for (int i = low; i <= high; i++) {
    v[i] = result[i-low];
  }

}

void mergeSort(vector<int> &v, int left, int right) {
  if (left < right) {
    int mid = left + (right-left)/2;
    mergeSort(v, left, mid);
    mergeSort(v, mid+1, right);
    merge(v, left, mid, right);
  }
}

// int main() {
//   vector<int> v1{1, 3, 7};
//   vector<int> v2{2, 3, 5, 6, 7};
//   vector<int> merged1 = merge2SortedVector(v1, v2);
//   printVector(merged1);
//
//   vector<int> v3{1, 3, 7, 2, 3, 5, 6, 7};
//   merge(v3, 0, 2, v3.size()-1);
//   cout << "v3: ";
//   printVector(v3);
//   cout << endl << endl;
//
//
//   vector<int> v4{10,5,30,15,7};
//   mergeSort(v4, 0, v4.size()-1);
//   printVector(v4);
//
//   return 1;
// }
