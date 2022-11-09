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

  void setAdj(vector<vector<int>> adjacencyList) {
    adj = adjacencyList;
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

  void BFSConnectedGraph(int source, int V, vector<bool> &visited, vector<int> &result) {
    deque<int> q;
    q.push_back(source);
    visited[source] = true;

    int curVertex;
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
  }

  vector<int> BFS(int source, int V) {
    vector<int> result;
    vector<bool> visited; // is the vetex added to the queue
    for (int i = 0; i < V; i++) {
      visited.push_back(false);
    }

    BFSConnectedGraph(source, V, visited, result);

    for (int i = 0; i < V; i++) {
      if (visited[i] == false) {
        BFSConnectedGraph(i, V, visited, result);
      }
    }
    return result;
  }

  void DFSConnectedGraph(int source, int V, vector<bool> &visited, vector<int> &result) {
    visited[source] = true;
    result.push_back(source);
    vector<int> neighbors = adj[source];
    for (auto neighbor: neighbors) {
      if (!visited[neighbor]) {
        DFSConnectedGraph(neighbor, V, visited, result);
      }
    }
  }

  vector<int> DFS(int source, int V) {
    vector<bool> visited;
    for (int i = 0; i < V; i++) {
      visited.push_back(false);
    }

    vector<int> result;
    DFSConnectedGraph(source, V, visited, result);
    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        DFSConnectedGraph(i, V, visited, result);
      }
    }
    return result;
  }


  bool IsCycleConnectedGraph(int source, int V, vector<bool> &visited, vector<int> &result) {
    deque<int> q;
    q.push_back(source);
    visited[source] = true;
    unordered_map<string, bool> edges;
    int countVertex = 0;

    int curVertex;
    while (!q.empty()) {
      curVertex = q.front();
      result.push_back(curVertex);
      q.pop_front();
      countVertex++;

      vector<int> neighbors = adj[curVertex];
      for (auto neighbor: neighbors) {
        // not visited
        string edge = curVertex > neighbor ? to_string(curVertex) + to_string(neighbor) : to_string(neighbor) + to_string(curVertex);
        edges[edge] = true;

        if (!visited[neighbor]) {
          visited[neighbor] = true;
          q.push_back(neighbor);

        }
      }
    }

    return countVertex == edges.size();
  }

  bool IsCycle(int V) {
    vector<int> result;
    vector<bool> visited; // is the vetex added to the queue
    for (int i = 0; i < V; i++) {
      visited.push_back(false);
    }
    bool isContainCycle = false;
    for (int i = 0; i < V; i++) {
      if (visited[i] == false) {
        isContainCycle = IsCycleConnectedGraph(i, V, visited, result);
        if (isContainCycle) {
          return true;
        }
      }
    }
    return false;
  }
};
