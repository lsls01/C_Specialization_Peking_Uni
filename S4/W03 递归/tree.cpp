#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(string a, string b) { return a > b; }
};

void print_blank() { cout << "|     "; }

void print(int deep, string s) {
  for (int i = 0; i < deep; i++)
    print_blank();
  cout << s << endl;
}

void fun(int deep, string s) {
  priority_queue<string, vector<string>, cmp> q;
  if (deep == 0) {
    cout << "ROOT" << endl;
    if (s[0] == 'f')
      q.push(s);
    if (s[0] == 'd')
      fun(deep + 1, s);
    if (s[0] == ']' || s[0] == '*') {
      while (!q.empty()) {
        print(deep, q.top());
        q.pop();
      }
      return;
    }
  } else
    print(deep, s);
  while (cin >> s) {
    if (s[0] == 'f')
      q.push(s);
    if (s[0] == 'd')
      fun(deep + 1, s);
    if (s[0] == ']' || s[0] == '*') {
      while (!q.empty()) {
        print(deep, q.top());
        q.pop();
      }
      return;
    }
  }
}

int main() {
  int t = 0;
  string s;
  while (cin >> s) {
    t++;
    if (t > 1)
      cout << endl;
    if (s[0] == '#')
      break;
    cout << "DATA SET " << t << ":" << endl;

    fun(0, s);
  }
  return 0;
}
