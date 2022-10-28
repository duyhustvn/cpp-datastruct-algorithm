#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode {
  bool isEnd;
  unordered_map<char, TrieNode*> child;

  TrieNode() {
    isEnd = false;
  }
};

class Trie {
public:
    TrieNode *root;

    Trie() {
      root = new TrieNode();
    }

    void insert(string word) {
      TrieNode *cur = root;

      for (int i = 0; i < word.size(); i++) {
        if (cur->child[word[i]] == NULL) {
          TrieNode *newNode = new TrieNode();
          cur->child[word[i]] = newNode;
        }
        cur = cur->child[word[i]];
      }

      cur->isEnd = true;
    }

    bool search(string word) {
        TrieNode *cur = root;

        for (int i = 0; i < word.size(); i++) {
          if (cur->child[word[i]] == NULL) {
            return false;
          }
          cur = cur->child[word[i]];
        }

        return cur != NULL && cur->isEnd;
    }

    bool startsWith(string prefix) {
      TrieNode *cur = root;

      for (int i = 0; i < prefix.size(); i++) {
        if (cur->child[prefix[i]] == NULL) {
          return false;
        }
        cur = cur->child[prefix[i]];
      }

      return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
