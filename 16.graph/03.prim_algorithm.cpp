#include <bits/stdc++.h>

using namespace std;

int primMST(vector<vector<int>> graph, int V, vector<int> &parent) {
  int result = 0;

  vector<bool> mSet(V, false);
  vector<int> key(V, INT_MAX);
  unordered_map<int, int> prevVertex;

  key[0] = 0;
  parent[0] = -1;

  for (int j = 0; j < V; j++) {
    // loop through the vertex
    // find the next vertex
    int u = -1;
    for (int i = 0; i < V; i++) {
      if (!mSet[i] && (u == -1 || key[i] < key[u])) {
        u = i;
      }
    }

    mSet[u] = true;
    result += key[u];

    // loop through list vertexs to update the edge distince value
    for (int i = 0; i < V; i++) {
      if (!mSet[i] && graph[u][i] != 0) {
        key[i] = min(key[i], graph[u][i]);
        parent[i] = u;
      }
    }
  }

  return result;
}
