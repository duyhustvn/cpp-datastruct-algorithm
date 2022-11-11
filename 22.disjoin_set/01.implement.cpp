#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  friend class DisjointSetTest;

  FRIEND_TEST(DisjointSetTest, MethodUninons);

  private:
  int V; // number of element
  vector<int> parent;
  vector<int> height;

  vector<int> getParent() {
    return parent;
  }

  public:
  DisjointSet(int numsOfElement) {
    V = numsOfElement;

    for (int i = 0; i < V; i++) {
      parent.push_back(i);
      height.push_back(0);
    }
  }

  // find root of x
  int find(int x) {
    if (x == parent[x]) {
      return x;
    }

    return find(parent[x]);
  }

  void unions(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);

    if (rootU == rootV) {
      return;
    }

    if (height[rootU] > height[rootV]) {
      parent[rootV] = rootU;
    } else if (height[rootV] > height[rootU]) {
      parent[rootU] = rootV;
    } else {
      parent[rootV] = rootU;
      height[rootU]++;
    }
  }
};
