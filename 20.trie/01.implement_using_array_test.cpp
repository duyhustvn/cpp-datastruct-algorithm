#include <iostream>
#include <gtest/gtest.h>
#include "01.implement_using_array.cpp"

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

TEST(TestDel, Delete) {
  TrieNode *root = new TrieNode();
  insert(root, "bac");
  del(root, "ba", 0);
  ASSERT_NE(root->child[1]->child[0]->child[2], nullptr);
  ASSERT_EQ(root->child[1]->child[0]->child[2]->isEnd, true);
  ASSERT_EQ(root->child[1]->child[0]->isEnd, false);


  insert(root, "ba");
  ASSERT_EQ(root->child[1]->child[0]->isEnd, true);
  ASSERT_EQ(root->child[1]->child[0]->child[2]->isEnd, true);

  del(root, "ba", 0);
  ASSERT_EQ(root->child[1]->child[0]->isEnd, false);
  ASSERT_EQ(root->child[1]->child[0]->child[2]->isEnd, true);
}

TEST(TestDel, DeleteWholeBranch) {
  TrieNode *root = new TrieNode();
  insert(root, "bac");
  ASSERT_NE(root->child[1], nullptr);
  root = del(root, "bac", 0);
  ASSERT_EQ(root, nullptr);
}

TEST(TestDel, DeleteLongerWord) {
  TrieNode *root = new TrieNode();
  insert(root, "ab");
  insert(root, "abcd");
  ASSERT_NE(root->child[0]->child[1]->child[2], nullptr);
  del(root, "abcd", 0);
  ASSERT_EQ(root->child[0]->child[1]->child[2], nullptr);
}

TEST(TestDel, DeleteAtCrossRoad) {
  TrieNode *root = new TrieNode();
  insert(root, "abef");
  insert(root, "abcd");
  ASSERT_NE(root->child[0]->child[1]->child[2], nullptr);
  del(root, "abcd", 0);
  ASSERT_EQ(root->child[0]->child[1]->child[2], nullptr);
}



int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
