#include <iostream>

using namespace std;

int main() {
  int n, m;
  int monkey[301];
  cin >> n >> m;
  for (int i = 1; i <= n; i++) monkey[i] = 1;
  int current = 0;
  int count = 0;
  while (count < n - 1) {
    for (int i = 0; i < m; i++) {
      current += 1;
      if (current == n + 1) current = 1;
      while (monkey[current] != 1) {
        current += 1;
        if (current == n + 1) current = 1;
      }
    }
    monkey[current] = 0;
    count += 1;
  }
  for (int i = 1; i <= n; i++)
    if (monkey[i] == 1) {
      cout << i << endl;
      break;
    }
  return 0;
}
