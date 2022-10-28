#include <iostream>
#include <gtest/gtest.h>
#include "02.implement_using_map.cpp"

using namespace std;

TEST(TestInsert, InsertWord) {
  Trie *t = new Trie();
  ASSERT_NE(t->root, nullptr);
  ASSERT_EQ(t->root->child['a'], nullptr);

  // INSERT abc
  t->insert("abc");

  ASSERT_EQ(t->root->child['b'], nullptr);

  ASSERT_NE(t->root->child['a'], nullptr);
  ASSERT_EQ(t->root->child['a']->isEnd, false);

  ASSERT_NE(t->root->child['a']->child['b'], nullptr);
  ASSERT_EQ(t->root->child['a']->child['b']->isEnd, false);

  ASSERT_NE(t->root->child['a']->child['b']->child['c'], nullptr);
  ASSERT_EQ(t->root->child['a']->child['b']->child['c']->isEnd, true);

  // INSERT ab
  t->insert("ab");
  ASSERT_NE(t->root->child['a'], nullptr);
  ASSERT_EQ(t->root->child['a']->isEnd, false);

  ASSERT_NE(t->root->child['a']->child['b'], nullptr);
  ASSERT_EQ(t->root->child['a']->child['b']->isEnd, true);


  // INSERT a
  t->insert("a");
  ASSERT_NE(t->root->child['a'], nullptr);
  ASSERT_EQ(t->root->child['a']->isEnd, true);

  // INSERT b
  t->insert("b");
  ASSERT_NE(t->root->child['b'], nullptr);
}


TEST(TestSearch, SearchWord) {
  Trie *t = new Trie();
  // INSERT abc
  t->insert("abc");

  ASSERT_EQ(t->search("abc"), true);
  ASSERT_EQ(t->search("abcd"), false);
  ASSERT_EQ(t->search("ab"), false);


  t->insert("ab");
  ASSERT_EQ(t->search("ab"), true);
}


int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
