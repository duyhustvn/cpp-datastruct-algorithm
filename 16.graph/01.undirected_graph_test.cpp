#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "01.undirected_graph.cpp"

using namespace std;

class UnDirectedGraphTest : public testing::Test {

};

TEST_F(UnDirectedGraphTest, MethodAdd) {
  UnDirectedGraph *graph = new UnDirectedGraph(5);
  graph->add(0, 1);

  vector<vector<int>> adj;
  adj  = graph->getAdj();
  ASSERT_EQ(adj[0][0], 1);
  ASSERT_EQ(adj[1][0], 0);


  ASSERT_NE(adj[0][1], 2);
  graph->add(0, 2);
  adj = graph->getAdj();
  ASSERT_EQ(adj[0][1], 2);
  ASSERT_EQ(adj[2][0], 0);
  graph->add(1, 3);
  adj = graph->getAdj();
  ASSERT_EQ(adj[1][1], 3);
  ASSERT_EQ(adj[3][0], 1);

  graph->printGraph(5);
}

TEST_F(UnDirectedGraphTest, MethodBFSOnConnectedGraph) {
  UnDirectedGraph *graph;
  vector<int> realResult;
  vector<int> expectedResult;

  graph = new UnDirectedGraph(6);
  graph->add(0,1);
  graph->add(0,2);
  graph->add(0,5);
  graph->add(1,3);
  graph->add(2,4);
  graph->add(3,5);
  graph->add(4,5);

  // graph->printGraph(6);
  realResult = graph->BFS(0, 6);

  expectedResult = {0,1,2,5,3,4};
  ASSERT_EQ(realResult, expectedResult);

  graph = new UnDirectedGraph(5);
  graph->add(0,1);
  graph->add(0,2);
  graph->add(1,2);
  graph->add(1,3);
  graph->add(2,3);
  graph->add(2,4);
  graph->add(3,4);

  realResult = graph->BFS(0, 5);
  expectedResult = {0,1,2,3,4};
  ASSERT_EQ(realResult, expectedResult);


  realResult = graph->BFS(2, 5);
  expectedResult = {2,0,1,3,4};
  ASSERT_EQ(realResult, expectedResult);


  realResult = graph->BFS(1, 5);
  expectedResult = {1,0,2,3,4};
  ASSERT_EQ(realResult, expectedResult);


  realResult = graph->BFS(4, 5);
  expectedResult = {4,2,3,0,1};
  ASSERT_EQ(realResult, expectedResult);
}

TEST_F(UnDirectedGraphTest, MethodBFSOnDisConnectedGraph) {
  UnDirectedGraph *graph;
  vector<int> realResult;
  vector<int> expectedResult;
  int V = 9;
  graph = new UnDirectedGraph(V);
  //        0              3
  //       / \            / \
  //      1   2          5   6
  //       \ /
  //        4          7-8
  graph->add(0,1);
  graph->add(0,2);
  graph->add(1,4);
  graph->add(2,4);
  graph->add(3,5);
  graph->add(3,6);
  graph->add(5,3);
  graph->add(7,8);

  // graph->printGraph(6);
  realResult = graph->BFS(0, V);

  expectedResult = {0,1,2,4,3,5,6,7,8};
  ASSERT_EQ(realResult, expectedResult);
}

TEST_F(UnDirectedGraphTest, MethodDFS) {
  UnDirectedGraph *graph;
  vector<int> realResult;
  vector<int> expectedResult;
  unordered_map<int, bool> visited;
  int V = 10;
  graph = new UnDirectedGraph(V);
  //        0                 7
  //       / \               / \
  //      1   4             8   9
  //      |  / \
  //      2 5 - 6
  //      |
  //      3
  graph->add(0,1);
  graph->add(0,4);
  graph->add(1,2);
  graph->add(2,3);
  graph->add(4,5);
  graph->add(4,6);
  graph->add(5,6);
  graph->add(7,8);
  graph->add(7,9);


  realResult = graph->DFS(0, V);
  expectedResult = {0,1,2,3,4,5,6,7,8,9};
  ASSERT_EQ(realResult, expectedResult);

  realResult = graph->DFS(2, V);
  expectedResult = {2,1,0,4,5,6,3,7,8,9};
  ASSERT_EQ(realResult, expectedResult);

  realResult = graph->DFS(4, V);
  expectedResult = {4,0,1,2,3,5,6,7,8,9};
  ASSERT_EQ(realResult, expectedResult);
}

TEST_F(UnDirectedGraphTest, MethodIsCycle) {
  UnDirectedGraph *graph;
  bool realResult;
  bool expectedResult;

  int V;

  V = 9;
  graph = new UnDirectedGraph(V);
  //        0              3
  //       / \            / \
  //      1   2          5   6
  //       \ /
  //        4          7-8
  graph->add(0,1);
  graph->add(0,2);
  graph->add(1,4);
  graph->add(2,4);
  graph->add(3,5);
  graph->add(3,6);
  graph->add(5,3);
  graph->add(7,8);

  // graph->printGraph(6);
  realResult = graph->IsCycleBFS(V);
  expectedResult = true;
  ASSERT_EQ(realResult, expectedResult);

  realResult = graph->IsCycleDFS(V);
  expectedResult = true;
  ASSERT_EQ(realResult, expectedResult);



  V = 9;
  graph = new UnDirectedGraph(V);
  //        0              3
  //       / \            / \
  //      1   2          5   6
  //         /
  //        4          7-8
  graph->add(0,1);
  graph->add(0,2);
  graph->add(2,4);
  graph->add(3,5);
  graph->add(3,6);
  graph->add(5,3);
  graph->add(7,8);

  // graph->printGraph(6);
  realResult = graph->IsCycleBFS(V);
  expectedResult = false;
  ASSERT_EQ(realResult, expectedResult);

  realResult = graph->IsCycleDFS(V);
  expectedResult = true;
  ASSERT_EQ(realResult, expectedResult);



  V = 9;
  graph = new UnDirectedGraph(V);
  //        0              3
  //       / \            / \
  //      1   2          5 - 6
  //         /
  //        4          7-8
  graph->add(0,1);
  graph->add(0,2);
  graph->add(2,4);
  graph->add(3,5);
  graph->add(3,6);
  graph->add(5,6);
  graph->add(5,3);
  graph->add(7,8);

  // graph->printGraph(6);
  realResult = graph->IsCycleBFS(V);
  expectedResult = true;
  ASSERT_EQ(realResult, expectedResult);

  realResult = graph->IsCycleDFS(V);
  expectedResult = true;
  ASSERT_EQ(realResult, expectedResult);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
