#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

struct cmp {
  bool operator()(string a, string b) { return a > b; }
};

void print_blank() { printf("|     "); }

void print(int deep, string s) {
  for (int i = 0; i < deep; i++)
    print_blank();
  printf("%s\n", s.c_str());
}

int fun(int deep, string s) {
  priority_queue<string, vector<string>, cmp> q;
  if (deep == 0) {
    printf("ROOT\n");
    if (s[0] == 'f')
      q.push(s);
    if (s[0] == 'd')
      fun(deep + 1, s);
    if (s[0] == ']' || s[0] == '*') {
      while (!q.empty()) {
        print(deep, q.top());
        q.pop();
      }
      return 1;
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
      return 1;
    }
  }
}

int main() {
  int t = 0;
  while (1) {
    t++;
    string s;
    cin >> s;
    if (s[0] == '#')
      return 0;
    if (t > 1)
      printf("\n");
    printf("DATA SET %d:\n", t);

    if (!fun(0, s))
      return 0;
  }
}
