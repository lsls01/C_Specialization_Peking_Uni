#include <iostream>

using namespace std;

int a[50], b[50];

class Fischer {
public:
  Fischer() {
    a[0] = 1;
    a[1] = 0;
    b[0] = 0;
    b[1] = 1;
    for (int i = 2; i < 50; i++) {
      a[i] = -1;
      b[i] = -1;
    }
  }
  int Cal(int m) {
    if (m % 2 == 1)
      return 0;
    return Cala(m) + Calb(m);
  }

private:
  int Cala(int m) {
    if (a[m] == -1)
      a[m] = 2 * Calb(m - 1) + Cala(m - 2);
    return a[m];
  }
  int Calb(int m) {
    if (b[m] == -1)
      b[m] = Cala(m - 1) + Calb(m - 2);
    return b[m];
  }
};

int main() {
  int n;
  Fischer ans;
  while (cin >> n && n >= 0)
    cout << ans.Cal(n) << endl;
  return 0;
}
