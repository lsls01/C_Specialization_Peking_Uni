#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int INFINITE = 1 << 31;
const int MAXL = 1000010;
const int MAXN = 1010;

int F[MAXL];        // final solution
int cowThere[MAXL]; // cowThere[i]=1 represents there is a cow
int N, L, A, B;

struct Fx {
  int x;
  int f;
  bool operator<(const Fx &a) const { return f > a.f; }
  Fx(int xx = 0, int ff = 0) : x(xx), f(ff) {}
}; // in Priority Queue, the smaller the value of f is, the prior the f is

priority_queue<Fx> qFx;

int main() {
  cin >> N >> L;
  cin >> A >> B;
  A <<= 1;
  B <<= 1; // A, B are diameter, not semimeter
  memset(cowThere, 0, sizeof(cowThere));
  for (int i = 0; i < N; ++i) {
    int s, e;
    cin >> s >> e;
    ++cowThere[s + 1];
    --cowThere[e];
  }

  int inCow = 0; // in current position, how many cows are there
  for (int i = 0; i <= L; i++) {
    F[i] = INFINITE;
    inCow += cowThere[i];
    cowThere[i] = inCow > 0;
  }

  for (int i = A; i <= B; i += 2) // initial PQ
    if (!cowThere[i]) {
      F[1] = 1;
      if (i <= B + 2 - A) // ensure x <= i - A
        qFx.push(Fx(i, 1));
    }

  for (int i = B + 2; i <= L; i += 2) {
    if (!cowThere[i]) {
      Fx fx;
      while (!qFx.empty()) {
        fx = qFx.top();
        if (fx.x < i - B)
          qFx.pop();
        else
          break;
      }
      if (!qFx.empty())
        F[i] = fx.f + 1;
    }

    if (F[i - A + 2] != INFINITE) {
      qFx.push(Fx(i - A + 2, F[i - A + 2]));
    }
  }

  if (F[L] == INFINITE)
    cout << -1 << endl;
  else
    cout << F[L] << endl;
  return 0;
}
