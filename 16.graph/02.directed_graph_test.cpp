#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "02.directed_graph.cpp"

using namespace std;

class DirectedGraphTest : public testing::Test {

};

TEST_F(DirectedGraphTest, MethodAdd) {
  DirectedGraph *graph;
  vector<vector<int>> adj;

  graph = new DirectedGraph(5);
  graph->add(0,2);
  adj = graph->getAdj();
  ASSERT_EQ(adj[0][0], 2);
  ASSERT_EQ(adj[2].size(), 0);

  graph->add(0,3);
  adj = graph->getAdj();
  ASSERT_EQ(adj[0][1], 3);

  graph->add(1,3);
  adj = graph->getAdj();
  ASSERT_EQ(adj[1][0], 3);

  graph->add(1,4);
  adj = graph->getAdj();
  ASSERT_EQ(adj[1][1], 4);
}

TEST_F(DirectedGraphTest, MethodTopologySorting) {
   DirectedGraph *graph;
   vector<vector<int>> adj;
   vector<int> expectedResult;
   vector<int> actualResult;

   //      0   3
   //     / \ / \
   //    2   1   4
   graph = new DirectedGraph(5);
   graph->add(0,2);
   graph->add(0,1);
   graph->add(3,1);
   graph->add(3,4);

   expectedResult = {0,3,2,1,4};
   actualResult = graph->topologySorting();
   ASSERT_EQ(actualResult, expectedResult);

   //    3   4
   //   / \ /
   //  0   1   2
   //   \ / \ /
   //    5   6
   graph = new DirectedGraph(7);
   graph->add(0,3);
   graph->add(0,5);
   graph->add(3,1);
   graph->add(5,1);
   graph->add(1,4);
   graph->add(1,6);
   graph->add(6,2);

   expectedResult = {0, 3, 5, 1, 4, 6, 2};
   actualResult = graph->topologySorting();
   ASSERT_EQ(actualResult, expectedResult);
}

TEST_F(DirectedGraphTest, MethodIsCycle) {
   DirectedGraph *graph;
   vector<vector<int>> adj;
   bool expectedResult;
   bool actualResult;

   //      0   3
   //     / \ / \
   //    2   1   4
   graph = new DirectedGraph(5);
   graph->add(0,2);
   graph->add(0,1);
   graph->add(3,1);
   graph->add(3,4);

   expectedResult = false;
   actualResult = graph->IsCycle();
   ASSERT_EQ(actualResult, expectedResult);

   //    3   4
   //   / \ /
   //  0   1   2
   //   \ / \ /
   //    5   6
   graph = new DirectedGraph(7);
   graph->add(0,3);
   graph->add(0,5);
   graph->add(3,1);
   graph->add(5,1);
   graph->add(1,4);
   graph->add(1,6);
   graph->add(6,2);

   expectedResult = false;
   actualResult = graph->IsCycle();
   ASSERT_EQ(actualResult, expectedResult);

   //   0 -> 1 -> 2
   //        ^    |
   //        |    v
   //        4 <- 3
   graph = new DirectedGraph(5);
   graph->add(0,1);
   graph->add(4,1);
   graph->add(1,2);
   graph->add(2,3);
   graph->add(3,4);

   expectedResult = true;
   actualResult = graph->IsCycle();
   ASSERT_EQ(actualResult, expectedResult);
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
