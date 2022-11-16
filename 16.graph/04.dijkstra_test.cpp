#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "04.dijkstra.cpp"

using namespace std;

class DijkstraTest : public testing::Test {

};


TEST_F(DijkstraTest, MethodDijkstra) {
  struct TestData {
    int V;
    vector<vector<int>> graph;
    vector<int> expectedResult;
  };

  vector<TestData> tests = {
    {
      6,
      {
        {0, 4, 2, 0, 0, 0},
        {0, 0, 5, 10, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 11},
        {0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 0},
      },
      {0,2,4,3,5}
    },
    {
      6,
      {
        {0, 4, 2, 0, 0, 0},
        {0, 0, 5, 2, 0, 0},
        {0, 0, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 11},
        {0, 0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0, 0},
      },
      {0,1,3,5}
    }
  };

  vector<int> actualResult;
  for (auto test: tests) {
    actualResult = dijkstra(test.graph, test.V, 0, 5);
    ASSERT_EQ(actualResult, test.expectedResult);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
