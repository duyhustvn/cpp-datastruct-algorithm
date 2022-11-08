#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class UnDirectedGraph {
  friend class UnDirectedGraphTest;

  FRIEND_TEST(UnDirectedGraphTest, MethodAdd);
  FRIEND_TEST(UnDirectedGraphTest, MethodBFS);

  private:
  int V;
  vector<vector<int>> adj;

  // use for testing only
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
      cout << i << ": ";
      for (auto e: adj[i]) {
        cout << e << " ";
      }
      cout << endl;
    }
  }

  vector<int> BFS(int source) {
    vector<int> result;
    deque<int> q;
    q.push_back(source);
    unordered_map<int, bool> visited;
    visited[source] = true;

    int curVertex;
    while (!q.empty()) {
      curVertex = q.front();
      result.push_back(curVertex);
      q.pop_front();

      vector<int> neighbors = adj[curVertex];
      for (auto neighbor: neighbors) {
        // not visited
        if (visited.find(neighbor) == visited.end()) {
          visited[neighbor] = true;
          q.push_back(neighbor);

        }
      }
    }
    cout << endl;
    return result;
  }
};
