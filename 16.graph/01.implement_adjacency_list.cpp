#include <iostream>
#include <vector>

using namespace std;

class UnDirectedGraph {
  friend class UnDirectedGraphTest;

  FRIEND_TEST(UnDirectedGraphTest, MethodAdd);

  private:
  int V;
  vector<vector<int>> adj;

  vector<vector<int>> getAdj() {
    return adj;
  }

  UnDirectedGraph(int V) {
    for (int i = 0; i < V; i++) {
      adj.push_back({});
    }
  }

  public:
  void add(int v, int u) {
    adj[v].push_back(u);
    adj[u].push_back(v);
  }

  void printGraph(int V) {
    for (int i = 0; i < V; i++) {
      for (auto e: adj[i]) {
        cout << e << " ";
      }
      cout << endl;
    }
  }

};

