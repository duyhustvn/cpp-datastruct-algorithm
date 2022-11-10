#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

class DirectedGraph {
  friend class DirectedGraphTest;

  FRIEND_TEST(DirectedGraphTest, MethodAdd);

  private:
  int V; // number of vertex
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

  vector<int> topologySorting() {
    // b1: generate the in-degree of all vertex
    // b2: add vertex with in-degree 0 to the queue
    // b3: pop from queue
    //     reduce the in-degree of the neigbors vertex
    //     if the in-degree of these neigbors is 0 add it to the queue

    vector<int> result;
    deque<int> q;
    vector<int> indegree;
    for (int i = 0; i < V; i++) {
      indegree.push_back(0);
    }

    // build indegree map
    for (int i = 0; i < V; i++) {
      for (auto e: adj[i]) {
        indegree[e]++;
      }
    }

    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        q.push_back(i);
      }
    }

    int currentVertex;
    while (!q.empty()) {
      currentVertex = q.front();
      q.pop_front();
      result.push_back(currentVertex);

      vector<int> neighbors = adj[currentVertex];
      for (auto neighbor: neighbors) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0) {
          q.push_back(neighbor);
        }
      }
    }

    return result;
  }

  bool IsCycle() {
    vector<int> result = topologySorting();
    return result.size() != V;
  }
};
