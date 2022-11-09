#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class UnDirectedGraph {
  friend class UnDirectedGraphTest;

  FRIEND_TEST(UnDirectedGraphTest, MethodAdd);
  FRIEND_TEST(UnDirectedGraphTest, MethodBFS);
  FRIEND_TEST(UnDirectedGraphTest, MethodBFSOnDisConnectedGraph);

  private:
  int V;
  vector<vector<int>> adj;

  // use for testing only
  vector<vector<int>> getAdj() {
    return adj;
  }


  public:
  UnDirectedGraph(int V) {
    for (int i = 0; i < V; i++) {
      adj.push_back({});
    }
  }

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

  vector<int> BFS(int source, int V) {
    vector<int> result;
    deque<int> q;
    q.push_back(source);
    unordered_map<int, bool> visited; // is the vetex added to the queue
    for (int i = 0; i < V; i++) {
      visited[i] = false;
    }

    visited[source] = true;

    int curVertex;
    bool finished = false;
    while (!finished) {
      while (!q.empty()) {
        curVertex = q.front();
        result.push_back(curVertex);
        q.pop_front();

        vector<int> neighbors = adj[curVertex];
        for (auto neighbor: neighbors) {
          // not visited
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push_back(neighbor);

          }
        }
      }

      finished = true;
      for (auto e: visited) {
        if (e.second == false) {
          q.push_back(e.first);
          finished = false;
          break;
        }
      }
    }
    return result;
  }
};
