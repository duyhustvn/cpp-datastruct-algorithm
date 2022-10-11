#include <iostream>
#include <stack>

using namespace std;


int arithmetic(string s) {
  stack<string> st;
  int result;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '+' || s[i] == '-') {
      string element = "";
      element.push_back(s[i]);
      st.push(element);
    } else if (s[i] == '*' || s[i] == '/') {
      char op = s[i];
      string num1 = st.top();
      st.pop();

      i++;
      string num2 = "";
      while ('0' <= s[i] && s[i] <= '9') {
        num2.push_back(s[i]);
        i++;
        if (i == s.length()) {
            break;
        }
      }

    //   result = (s[i] == '*') ?  stoi(num1) * stoi(num2) : stoi(num1) / stoi(num2);

    if (op == '*') {
        result = stoi(num1) * stoi(num2);
      } else {
        result = stoi(num1) / stoi(num2);
      }


      st.push(to_string(result));
      i--;
  } else {
      string num = "";
      while ('0' <= s[i] && s[i] <= '9') {
        num.push_back(s[i]);
        i++;
      }
      i--;
      st.push(num);
    }
  }

    while (!st.empty()) {
      cout << st.top() << " ";
      st.pop();
    }

  return 0;
}


int main() {
  string s = "2*3+4*4-15/5*3";
  arithmetic(s);
  return 0;
}
