#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
  TrieNode *child[26];
  bool isEnd;

  TrieNode() {
    isEnd = false;
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
  }
};

bool search(TrieNode *root, string s) {
  TrieNode *cur = root;

  for (int i = 0; i < s.size(); i++) {
    int index = s[i] - 'a';

    if (cur->child[index] == NULL) {
      return false;
    }
    cur = cur->child[index];
  }
  return (cur != NULL && cur->isEnd);
}

void insert(TrieNode *root, string s) {
  TrieNode *cur = root;
  for (int i = 0; i < s.size(); i++) {
    int index = s[i]-'a';
    if (cur->child[index] == NULL) {
      TrieNode *newNode = new TrieNode();
      cur->child[index] = newNode;
    }
    cur = cur->child[index];
  }
  cur->isEnd = true;
}

bool hasChild(TrieNode *cur) {
  for (int i = 0; i < 26; i++) {
    if (cur->child[i] != NULL) {
      return true;
    }
  }
  return false;
}

TrieNode* del(TrieNode *root, string s, int index) {
  if (root == NULL) {
    return NULL;
  }

  if (index == s.size()) {
    root->isEnd = false;
    if (!hasChild(root)) {
      delete(root);
      return NULL;
    }
    return root;
  }

  int i = s[index] - 'a';
  root->child[i] = del(root->child[i], s, index+1);

  if (!hasChild(root) && !root->isEnd) {
    delete(root);
    return NULL;
  }

  return root;
}
