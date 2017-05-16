#include <iostream>
#include <stack>

using namespace std;

struct Problem {
  int n;
  char src, mid, dest;
  Problem(int nn, char s, char m, char d) : n(nn), src(s), mid(m), dest(d) {}
};

stack<Problem> stk;

int main() {
  int n;
  cin >> n;
  stk.push(Problem(n, 'A', 'B', 'C'));
  while (!stk.empty()) {
    Problem curPrb = stk.top();
    stk.pop();
    if (curPrb.n == 1)
      cout << curPrb.src << "->" << curPrb.dest << endl;
    else {
      stk.push(Problem(curPrb.n - 1, curPrb.mid, curPrb.src, curPrb.dest));
      stk.push(Problem(1, curPrb.src, curPrb.mid, curPrb.dest));
      stk.push(Problem(curPrb.n - 1, curPrb.src, curPrb.dest, curPrb.mid));
    }
  }
  return 0;
}
