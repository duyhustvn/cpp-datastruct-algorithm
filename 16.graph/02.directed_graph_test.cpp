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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
