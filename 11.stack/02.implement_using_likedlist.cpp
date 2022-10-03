#include <iostream>

using namespace std;

struct StackNode {
  int data;
  StackNode *next;
  StackNode(int a) {
    data = a;
    next = NULL;
  }
};

class MyStack {
  private:
  StackNode *top;

  public:
  void push(int);
  int pop();
  MyStack() {
    top = NULL;
  }
};


//Function to push an integer into the stack.
void MyStack ::push(int x)
{
    // Your Code
   StackNode *s = new StackNode(x);
  if (top == NULL) {
    top = s;
    return;
  }
  s->next = top;
  top = s;
}

//Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if (top == NULL) {
    return -1;
  }
  StackNode *tmp = top;
  int v = top->data;
  top = top->next;
  delete(tmp);
  return v;
}
