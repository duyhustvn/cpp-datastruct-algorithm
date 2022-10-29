// https://leetcode.com/problems/map-sum-pairs/

#include <iostream>
#include <unordered_map>

using namespace std;

struct TrieNode {
    int freq;
    bool isEnd;
    unordered_map<char, TrieNode*> child;
    TrieNode() {
        isEnd = false;
        freq = 0;
    }
};

class MapSum {
public:
    TrieNode *root;
    unordered_map<string, int>insertedWord;
    MapSum() {
        root = new TrieNode();
    }

    void insert(string key, int val) {
        bool isWordInserted = false;
        // found in map -> already inserted
        if (insertedWord.find(key) != insertedWord.end()) {
            isWordInserted = true;
        }

        TrieNode* cur = root;
        for (int i = 0; i < key.size(); i++) {
            if (cur->child[key[i]] != NULL) {
                cur->child[key[i]]->freq += val;
                if (isWordInserted) {
                    cur->child[key[i]]->freq -= insertedWord[key];
                }
            } else {
                TrieNode *newNode = new TrieNode();
                newNode->freq = val;
                cur->child[key[i]] = newNode;
            }
            cur = cur->child[key[i]];
        }
        cur->isEnd = true;

        insertedWord[key] = val;
    }

    int sum(string prefix) {
        TrieNode* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            if (cur->child[prefix[i]] == NULL) {
                return 0;
            }
            cur = cur->child[prefix[i]];
        }
        if (cur == NULL) {
            return 0;
        }
        return cur->freq;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
