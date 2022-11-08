#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "01.implement_adjacency_list.cpp"

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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
