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

int height(Node *root) {
  if (root == NULL) {
      return 0;
  }

  return max(height(root->left), height(root->right)) + 1;
}

int size(Node *root) {
  int count = 0;
  queue<Node*> q;
  q.push(root);
  while (!q.empty()) {
    Node *currentNode = q.front();
    q.pop();
    count++;

    if (currentNode->left != NULL) {
      q.push(currentNode->left);
    }
    if (currentNode->right != NULL) {
      q.push(currentNode->right);
    }
  }
  return count;
}

int getSize(Node *root) {
  if (root == NULL) {
    return 0;
  }
  return getSize(root->left) + getSize(root->right) + 1;
}

void nodeAtDistanceK(Node *root, int k) {
  if (root == NULL) return;

  if (k == 0) {
    cout << root->key << " ";
  }

    nodeAtDistanceK(root->left, k-1);
    nodeAtDistanceK(root->right, k-1);
}

int getMax(Node *root) {
  if (root != NULL) {
    return max(root->key, max(getMax(root->left), getMax(root->right)));
  }
  return INT_MIN;
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

  cout << "height of tree: " << height(root) << endl;

  int k = 0;
  cout << "node at distance " << k << " are: ";
  nodeAtDistanceK(root, k);
  cout << endl;


  k = 1;
  cout << "node at distance " << k << " are: ";
  nodeAtDistanceK(root, k);
  cout << endl;

  k = 2;
  cout << "node at distance " << k << " are: ";
  nodeAtDistanceK(root, k);
  cout << endl;


  k = 3;
  cout << "node at distance " << k << " are: ";
  nodeAtDistanceK(root, k);
  cout << endl;

  cout << "Size of the tree: ";
  cout << size(root) << endl;


  cout << "Size of the tree: ";
  cout << getSize(root) << endl;

  cout << "Max: ";
  cout << getMax(root) << endl;
  return 0;
}

