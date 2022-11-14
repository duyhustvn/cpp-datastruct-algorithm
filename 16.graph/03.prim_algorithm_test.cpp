#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "03.prim_algorithm.cpp"

using namespace std;

class PrimTest : public testing::Test {

};

TEST_F(PrimTest, MethodPrimMST) {
  struct TestData {
    int V;
    vector<vector<int>> graph;
    int expectedResult;
    vector<int> expectedPath;
  };

  vector<TestData> tests = {
    {
      4,
      {
        {0, 5, 8, 0},
		{5, 0, 10, 15 },
		{8, 10, 0, 20 },
		{0, 15, 20, 0 },
      },
      28,
      {-1, 0, 0, 1},
    }
  };

  int actualResult;
  for (auto test: tests) {
    vector<int> parent(test.V);
    actualResult = primMST(test.graph, test.V, parent);
    ASSERT_EQ(actualResult, test.expectedResult);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
