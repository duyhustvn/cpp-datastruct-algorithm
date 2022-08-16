#include <iostream>
#include <queue>

using namespace std;

struct Node {
  int key;
  struct Node *left;
  struct Node *right;

  Node(int k) {
    key = k;
    left = right = NULL;
  }
};

void BFS(Node *root) {
  queue<Node*> q;
  q.push(root);

  while (!q.empty()) {
    Node *curNode = q.front();
    cout << curNode->key << " ";
    q.pop();
    if (curNode->left != NULL) {
      q.push(curNode->left);
    }
    if (curNode->right != NULL) {
      q.push(curNode->right);
    }
  }
}

void DFSInorder(Node *root) {
  // LEFT -> ROOT -> RIGHT
  if (root!= NULL) {
    DFSInorder(root->left);
    cout << root->key << " ";
    DFSInorder(root->right);
  }
}

void DFSPreorder(Node *root) {
  // ROOT -> LEFT -> RIGHT
  if (root != NULL) {
    cout << root->key << " ";
    DFSPreorder(root->left);
    DFSPreorder(root->right);
  }
}

void DFSPostorder(Node *root) {
  // LEFT -> RIGHT -> ROOT
  if (root != NULL) {
    DFSPostorder(root->left);
    DFSPostorder(root->right);
    cout << root->key << " ";
  }
}


int main() {
  /*
                 10
                /  \
              20   30
              /\    \
            40 50   60
               /\
             70 80
  */
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->left->right->left = new Node(70);
  root->left->right->right = new Node(80);
  root->right->right = new Node(60);

  cout << "BFS" << endl;
  BFS(root);
  cout << endl;

  cout << "DFSInorder" << endl;
  DFSInorder(root);
  cout << endl;


  cout << "DFSPreorder" << endl;
  DFSPreorder(root);
  cout << endl;


  cout << "DFSPostorder" << endl;
  DFSPostorder(root);
  cout << endl;
  return 0;
}

