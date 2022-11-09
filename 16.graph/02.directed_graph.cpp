#include <iostream>
#include <vector>

using namespace std;

class DirectedGraph {
  friend class DirectedGraphTest;

  FRIEND_TEST(DirectedGraphTest, MethodAdd);

  private:
  int V;
  vector<vector<int>> adj;

  vector<vector<int>> getAdj() {
    return adj;
  }

  public:
  DirectedGraph(int numsVertex) {
    V = numsVertex;
    for (int i = 0; i < numsVertex; i++) {
      adj.push_back({});
    }
  }

  void add(int v, int u) {
    adj[v].push_back(u);
  }

  void printGraph() {
    for (int i = 0; i < V; i++) {
      for (auto e: adj[i]) {
        cout << e << " ";
      }
      cout << endl;
    }
  }
};
