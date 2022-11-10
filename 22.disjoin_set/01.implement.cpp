#include <iostream>
#include <vector>

using namespace std;

class DisjointSet {
  friend class DisjointSetTest;

  FRIEND_TEST(DisjointSetTest, MethodUninons);

  private:
  int V; // number of element
  vector<int> parent;

  vector<int> getParent() {
    return parent;
  }

  public:
  DisjointSet(int numsOfElement) {
    V = numsOfElement;

    for (int i = 0; i < V; i++) {
      parent.push_back(i);
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
    // already same group
    if (rootU == rootV) {
      return;
    }
    parent[rootV] = rootU;
  }
};
