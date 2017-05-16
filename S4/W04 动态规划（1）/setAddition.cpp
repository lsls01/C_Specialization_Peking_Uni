#include <iostream>

using namespace std;

int countHelper(int sum, int arrayA[], int numA, int arrayB[], int numB) {
  int count = 0;
  for (int i = 0; i < numA; ++i) {
    for (int j = 0; j < numB; ++j) {
      if (arrayA[i] + arrayB[j] == sum) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int sum, numA, numB;
  int arrayA[10001], arrayB[10001];
  int num;

  cin >> num;
  while (num--) {
    cin >> sum;
    cin >> numA;
    for (int i = 0; i < numA; ++i) {
      cin >> arrayA[i];
    }
    cin >> numB;
    for (int j = 0; j < numB; ++j) {
      cin >> arrayB[j];
    }
    int count = countHelper(sum, arrayA, numA, arrayB, numB);
    cout << count << endl;
  }

  return 0;
}
