#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "01.0-1knapsack.cpp"

using namespace std;

class KnapsackTest : public testing::Test {

};

TEST_F(KnapsackTest, MethodKnapsack) {
  struct DataTest {
    int W;
    vector<int> val;
    vector<int> wt;
    int expectedMaxValue;
  };

  vector<DataTest> tests = {
    {4, {1,2,3}, {4,5,1}, 3},
    {10, {10,40,30,50}, {5,4,6,3}, 90},
    {50, {60,100,120}, {10,20,30}, 220},
  };

  for (auto test: tests) {
    int actualMaxValue = knapSack(test.W, test.wt, test.val);
    ASSERT_EQ(test.expectedMaxValue, actualMaxValue);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
