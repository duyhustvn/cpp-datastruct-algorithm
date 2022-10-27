#include <iostream>
#include <gtest/gtest.h>
#include "01.implement.cpp"

using namespace std;

TEST(TestInsert, InsertWordThatDoesntHasPrefix) {
  TrieNode *root = new TrieNode();
  insert(root, "bad");

  ASSERT_NE(root->child[1], nullptr);
  ASSERT_EQ(root->child[1]->isEnd, false);

  ASSERT_NE(root->child[1]->child[0], nullptr);
  ASSERT_EQ(root->child[1]->child[0]->isEnd, false);

  ASSERT_NE(root->child[1]->child[0]->child[3], nullptr);
  ASSERT_EQ(root->child[1]->child[0]->child[3]->isEnd, true);
}

TEST(TestInsert, InsertWordThatHasPrefix) {
  TrieNode *root = new TrieNode();
  insert(root, "bac");
  insert(root, "bad");

  ASSERT_NE(root->child[1]->child[0], nullptr);
  ASSERT_EQ(root->child[1]->child[0]->isEnd, false);

  insert(root, "ba");

  ASSERT_NE(root->child[1]->child[0], nullptr);
  ASSERT_EQ(root->child[1]->child[0]->isEnd, true);
}

TEST(TestSearch, Search) {
  TrieNode *root = new TrieNode();
  insert(root, "bac");

  ASSERT_EQ(search(root, "bac"), true);
  ASSERT_EQ(search(root, "bad"), false);

  insert(root, "bad");
  ASSERT_EQ(search(root, "bad"), true);
  ASSERT_EQ(search(root, "ba"), false);


  insert(root, "ba");
  ASSERT_EQ(search(root, "ba"), true);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
