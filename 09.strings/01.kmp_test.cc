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
        {"AAAA", {0,1,2,3}},
        {"ABCDE", {0,0,0,0,0}},
        {"AABAACAABAA", {0,1,0,1,2,0,1,2,3,4,5}},
        {"AAACAAAAAC", {0, 1, 2, 0, 1, 2, 3, 3, 3, 4}},
        {"AAABAAA", {0, 1, 2, 0, 1, 2, 3}},
    };

    KMP *kmp = new KMP();
    vector<int> actualLPS;
    for (auto test: tests) {
        actualLPS = kmp->computeLPSArray(test.input);
        ASSERT_EQ(actualLPS, test.expectedLPS);


        actualLPS = kmp->computeLPSArrayBruteForce(test.input);
        ASSERT_EQ(actualLPS, test.expectedLPS);
    }
}

TEST_F(KMPTest, MethodKmp) {
    struct DataTest {
        string txt; // source string
        string ptn; // pattern
        vector<int> expectedIndexs;
    };
    vector<DataTest> tests{
        {"aabaacaadaabaaba", "aaaab", {}},
        {"aabaacaadaabaaba", "caada", {5}},
        {"THIS IS A TEST TEST TEXT TEST", "TEST", {10, 15, 25}}
    };
    KMP *kmp = new KMP();
    vector<int> actualIndexs;
    for (auto test: tests) {
        actualIndexs = kmp->find(test.txt, test.ptn);
        ASSERT_EQ(actualIndexs, test.expectedIndexs);
    }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
