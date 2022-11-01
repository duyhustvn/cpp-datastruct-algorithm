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
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
