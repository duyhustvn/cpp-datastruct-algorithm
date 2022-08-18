#include <iostream>
#include <queue>
#include <stack>

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

// DFS Inorder using recursive
void DFSInorder(Node *root) {
  // LEFT -> ROOT -> RIGHT
  if (root!= NULL) {
    DFSInorder(root->left);
    cout << root->key << " ";
    DFSInorder(root->right);
  }
}

void printStack(stack<Node*>s) {
  while (!s.empty()) {
    Node *curNode = s.top();
    s.pop();
    cout << curNode->key << " ";
  }
  cout << endl;
}

// DFS Inorder using iterator
void DFSInorderUsingIterator(Node *root) {
  Node *curNode = root;
  stack<Node*> s;
  while (curNode != NULL) {
    s.push(curNode);
    curNode = curNode->left;
  }

  // printStack(s);

  while (!s.empty()) {
    Node *curNode = s.top();
    cout << curNode->key << " ";
    s.pop();
    if (curNode->right != NULL) {
      s.push(curNode->right);
      curNode = curNode->right;

      while (curNode->left != NULL) {
        s.push(curNode->left);
        curNode = curNode->left;
      }
    }
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


// DFS Inorder using iterator
void DFSPreorderUsingIterator(Node *root) {
  stack<Node*> s;
  s.push(root);

  while(!s.empty()) {
    Node *curNode = s.top();
    s.pop();
    cout << curNode->key << " ";

    if (curNode->right != NULL) {
      s.push(curNode->right);
    }
    if (curNode->left != NULL) {
      s.push(curNode->left);
    }
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

void DFSPostorderUsingIterator(Node *root) {
  stack<Node*> revertOrder;
  stack<Node*> s;

  Node* curNode = root;
  while (curNode != NULL) {
    revertOrder.push(curNode);
    s.push(curNode);
    curNode = curNode->right;
  }

  while (!s.empty()) {
    curNode = s.top();
    s.pop();

    if (curNode->left != NULL) {
      revertOrder.push(curNode->left);
      s.push(curNode->left);
      curNode = curNode->left;

      while (curNode->right != NULL) {
        revertOrder.push(curNode->right);
        s.push(curNode->right);
        curNode = curNode->right;
      }
    }
  }

  while (!revertOrder.empty()) {
    curNode = revertOrder.top();
    revertOrder.pop();
    cout << curNode->key << " ";
  }
  cout << endl;
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
                 \
                 90
  */
  Node *root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->left->left = new Node(40);
  root->left->right = new Node(50);
  root->left->right->left = new Node(70);
  root->left->right->right = new Node(80);
  root->left->right->right->right = new Node(90);
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

  cout << "DFS inorder using iterator" << endl;
  DFSInorderUsingIterator(root);
  cout << endl;

  cout << "DFS preorder using iterator" << endl;
  DFSPreorderUsingIterator(root);
  cout << endl;

  cout << "DFS postorder using iterator" << endl;
  DFSPostorderUsingIterator(root);
  cout << endl;
  return 0;
}

