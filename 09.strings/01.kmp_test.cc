#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "01.kmp.cc"

using namespace std;

class KMPTest : public testing::Test {

};

TEST_F(KMPTest, MethodComputeLPSArray) {
    struct DataTest {
        string input;
        vector<int> expectedLPS;
    };

    vector<DataTest> tests{
        {"abacabad", {0,0,1,0,1,2,3,0}},
        {"abbabb", {0,0,0,1,2,3}},
    };

    KMP *kmp = new KMP();
    vector<int> actualLPS;
    for (auto test: tests) {
        actualLPS = kmp->computeLPSArray(test.input);
        ASSERT_EQ(actualLPS, test.expectedLPS);
    }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
