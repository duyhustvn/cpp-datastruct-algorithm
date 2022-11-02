#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "04.find_max_xor.cpp"

using namespace std;

class RSTTest : public testing::Test {

};

TEST_F(RSTTest, MethodConvertToBinary) {
    RST *rst = new RST();
    string result;

    result = rst->convertToBinary(1);
    ASSERT_EQ(result, "1");

    result = rst->convertToBinary(2);
    ASSERT_EQ(result, "10");

    result = rst->convertToBinary(3);
    ASSERT_EQ(result, "11");

    result = rst->convertToBinary(7);
    ASSERT_EQ(result, "111");

    result = rst->convertToBinary(1, 3);
    ASSERT_EQ(result, "001");

    result = rst->convertToBinary(2, 3);
    ASSERT_EQ(result, "010");

    result = rst->convertToBinary(3,3);
    ASSERT_EQ(result, "011");

    result = rst->convertToBinary(7, 3);
    ASSERT_EQ(result, "111");
}

TEST_F(RSTTest, MethodInsert) {
    RST *rst = new RST();
    rst->setMaxLengthBinary(3);
    ASSERT_EQ(rst->getRootNode()->child[0], nullptr);
    rst->insert(1); // Insert 001

    ASSERT_NE(rst->getRootNode()->child[0], nullptr);
    ASSERT_NE(rst->getRootNode()->child[0]->child[0], nullptr);
    ASSERT_NE(rst->getRootNode()->child[0]->child[0]->child[1], nullptr);
    ASSERT_EQ(rst->getRootNode()->child[0]->child[0]->child[1]->val, 1);


    ASSERT_EQ(rst->getRootNode()->child[0]->child[1], nullptr);
    rst->insert(2); // Insert 010
    ASSERT_NE(rst->getRootNode()->child[0], nullptr);
    ASSERT_NE(rst->getRootNode()->child[0]->child[1], nullptr);
    ASSERT_NE(rst->getRootNode()->child[0]->child[1]->child[0], nullptr);
    ASSERT_EQ(rst->getRootNode()->child[0]->child[1]->child[0]->val, 2);
}

TEST_F(RSTTest, MethodGetMaxXOR) {
    RST *rst = new RST();
    int arr[] = {3,10,5,25,2,8}; // 25 -> 11001
    rst->setMaxLengthBinary(5);
    for (int i = 0; i < 6; i++) {
      rst->insert(arr[i]);
    }

    ASSERT_EQ(rst->getMaxXOR(5), 25);
    ASSERT_EQ(rst->getMaxXOR(25), 5);
}

TEST_F(RSTTest, MethodFindMaximumXOR) {
    RST *rst = new RST();
    vector<int> nums{3,10,5,25,2,8}; // 25 -> 11001

    ASSERT_EQ(rst->findMaximumXOR(nums), 28);

    vector<int> nums1{14,70,53,83,49,91,36,80,92,51,66,70};
    ASSERT_EQ(rst->findMaximumXOR(nums1), 127);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
