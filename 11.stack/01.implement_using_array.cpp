#include <iostream>

using namespace std;

const int stackMax=100000;
int stack[stackMax];
int top=-1;

void push(int data);

void pop();

void display();

// } Driver Code Ends
//User function Template for C++

//Complete these functions

//Function to push data at the top of stack
void push(int data)
{
    //Your code here
    if (top == stackMax-1) {
        cout << "Stack Full" << endl;
        return;
    }
    top++;
    stack[top] = data;
}
//Function to pop the topmost data
void pop()
{
    // cout << "pop" << endl;
    //Your code here
    if (top == -1) {
        cout << "Stack Empty" << endl;
        return;
    }
    // cout << stack[top] << endl;
    top--;
}
//Function to display the stack from index 0
void display()
{
    // cout << "display" << endl;
    //Your code here
    if (top == -1) {
        cout << "-1" << endl;
        return;
    }
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}
