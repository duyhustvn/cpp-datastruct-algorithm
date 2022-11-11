#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "01.implement.cpp"

using namespace std;

class DisjointSetTest : public testing::Test {

};

TEST_F(DisjointSetTest, MethodUninons) {
  DisjointSet *d;
  int V;
  vector<int> parent;

  V = 8;
  d = new DisjointSet(V);

  parent = d->getParent();
  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }

  d->unions(0,1);
  parent = d->getParent();
  ASSERT_EQ(parent[1], 0);


  d->unions(1,4);
  parent = d->getParent();
  ASSERT_EQ(parent[4], 0);


  d->unions(2,3);
  parent = d->getParent();
  ASSERT_EQ(parent[3], 2);

  d->unions(3,4);
  parent = d->getParent();
  ASSERT_EQ(parent[0], 2);


  d->unions(6,7);
  parent = d->getParent();
  ASSERT_EQ(parent[7], 6);

  d->unions(5,6);
  parent = d->getParent();
  ASSERT_EQ(parent[5], 6);
}


TEST_F(DisjointSetTest, MethodFind) {
  DisjointSet *d;
  int V;
  vector<int> parent;

  V = 6;
  d = new DisjointSet(V);

  ASSERT_EQ(d->find(0), 0);
  d->unions(0,1);
  ASSERT_EQ(d->find(1), 0);

  d->unions(1,4);
  ASSERT_EQ(d->find(4), 0);

  d->unions(2,3);
  ASSERT_EQ(d->find(3), 2);

  d->unions(3,4);
  ASSERT_EQ(d->find(4), 2);
  ASSERT_EQ(d->find(1), 2);
  ASSERT_EQ(d->find(0), 2);

  d->unions(3,5);
  ASSERT_EQ(d->find(5), 2);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
