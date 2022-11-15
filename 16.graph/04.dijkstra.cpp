#include <bits/stdc++.h>

using namespace std;

struct MyCmp {
  bool operator() (pair<int, int> p1, pair<int, int> p2) {
    return p1.second > p2.second;
  }
};


void printPQ(priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq) {
  cout << "CURRENT PQ: " << endl;
  while (!pq.empty()) {
    pair<int, int> top = pq.top();
    pq.pop();
    printf("%c: %d\t", top.first + 'a', top.second);
  }
  cout << endl;
}

void buildPath(unordered_map<int, int> parent, int source, int des) {
  int findVer = des;
  cout << "PATH: " << endl;
  while (findVer != source) {
    printf("%c <- ", findVer + 'a');
    for (auto e: parent) {
      if (e.first == findVer) {
        findVer = e.second;
        break;
      }
    }
  }
  printf("%c", findVer + 'a');
  cout << endl;
}

unordered_map<int, int> initDistance(int V) {
  unordered_map<int, int> m;
  for (int i = 0; i < V; i++) {
    m[i] = INT_MAX;
  }
  return m;
}

void dijkstra(vector<vector<int>> graph, int V, int source, int destination) {
  // graph is matrix
  //  [0,5,10,0],
  //  [5,0,3,20],
  //  [10,3,0,2],
  //  [0,20,2,0]
  //

  // Start from source, put it to priority queue
  // while pq is not empty
  //   pop first element
  //   add to visited
  //   count the distance of neigbors node
  //   push back to the pq

  priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> pq; // vertex -> distance

  // store the distance from source to a point
  // source: A
  // a record in distance: {B: 2} mean the distance from A to B is 2
  // {C: 4} mean the distance from A to C is 4
  unordered_map<int, int> distance = initDistance(V);

  unordered_map<int, int> parent;

  pq.push({source, 0});

  unordered_map<int, bool> visited;

  while (!pq.empty()) {
    // printPQ(pq);

    pair<int, int> cur = pq.top();
    pq.pop();

    if (visited[cur.first] == true) {
      continue;
    } else {
      visited[cur.first] = true;
    }

    int curVertex = cur.first;
    int curPathSum = cur.second;

    // cout << curVertex << ": " << curPathSum << endl;
    // printf("%c: %d\n", curVertex + 'a', curPathSum);

    if (curVertex == destination) {
      buildPath(parent, source, destination);
      return;
    }

    for (int j = 0; j < V; j++) {
      if (graph[curVertex][j] != 0) {
        int pathSum = curPathSum + graph[curVertex][j];
        if (pathSum < distance[j]) {
          pq.push({j, pathSum});
          distance[j] = pathSum;
          parent[j] = curVertex;
        }
      }
    }
  }
}
