#include <iostream>
#include <vector>

using namespace std;

bool isSafe(string str, int l, int i, int r) {
  if (l !=0 && str[l-1] == 'A' && str[i] == 'B') {
    cout << "not safe 1: " << str << " i: " << i << " l: " << l << endl;
    return false;
  }

  if (r == (l+1) && str[i] == 'A' && str[l] == 'B') {
    cout << "not safe 2: " << str << " i: " << i << " l: " << l << endl;
    return false;
  }

  return true;
}

void permute(string str, int l, int r, vector<string> &v) {
  if (l == r) {
    v.push_back(str);
  } else {
    for (int i = l; i <= r; i++) {
      if (l == r) {
        v.push_back(str);
      } else {
        if (isSafe(str, l, i, r)) {
            swap(str[i], str[l]);
            permute(str, l+1, r, v);
            swap(str[i], str[l]);
        }
      }
    }
  }
}

int main() {
  string str = "ABCD";
  vector<string> v;
  permute(str, 0, str.size()-1, v);

  cout << endl;
  cout << v.size() << " possibility" << endl;
  for (auto e: v) {
    cout << e << endl;
  }

  return 0;
}
