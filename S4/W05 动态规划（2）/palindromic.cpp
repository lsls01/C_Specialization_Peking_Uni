#include <iostream>

using namespace std;

int N;
long upNums[251][251];

long upNum(int N, int max) {
  long count = 0;
  if (upNums[N][max] != -1)
    return upNums[N][max];

  if (max == 1 || N == 0) {
    upNums[N][max] = 1;
    return 1;
  }
  if (max < 1) {
    upNums[N][max] = 0;
    return 0;
  }
  if (max > N) {
    upNums[N][max] = upNum(N, N);
    return upNums[N][N];
  }
  for (int i = 1; i <= max; ++i) {
    count += upNum(N - i, i);
  }
  upNums[N][max] = count;
  return count;
}

long conbinationNum(int N) {
  bool even = (N + 1) % 2;
  long count = 0;
  for (int i = 1; i <= N; ++i) {
    int base, numOfI = 1;
    if (even) {
      if ((i % 2)) {
        base = 2;
        numOfI = 2;
      } else {
        base = 1;
      }
      while ((i * numOfI) <= N) {
        count += upNum((N - (i * numOfI)) / 2, i - 1);
        numOfI += base;
      }
    } else {
      if (i % 2 == 1) {
        base = 2;
        while (i * numOfI <= N) {
          count += upNum((N - (i * numOfI)) / 2, i - 1);
          numOfI += base;
        }
      }
    }
  }
  return count;
}

int main() {
  for (int i = 0; i < 251; ++i) {
    for (int j = 0; j < 251; ++j) {
      upNums[i][j] = -1;
    }
  }
  cin >> N;
  while (N != 0) {
    cout << N << " " << conbinationNum(N) << endl;
    cin >> N;
  }
  return 0;
}
