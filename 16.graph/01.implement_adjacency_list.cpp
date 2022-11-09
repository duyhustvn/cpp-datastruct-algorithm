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
    vector<bool> visited; // is the vetex added to the queue
    for (int i = 0; i < V; i++) {
      visited.push_back(false);
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
       for (int i = 0; i < V; i++) {
         if (visited[i] == false) {
           visited[i] = true;
           q.push_back(i);
           finished = false;
           break;
         }
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

};
