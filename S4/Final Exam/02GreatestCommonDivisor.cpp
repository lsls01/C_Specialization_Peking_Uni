#include <iostream>

using namespace std;

int main() {
  int M, N;
  while (cin >> M >> N) {
    int r = M % N;
    while (r) {
      M = N;
      N = r;
      r = M % N;
    }
    cout << N << endl;
  }
  return 0;
}
