#include <algorithm>
#include <stdio.h>

using namespace std;

#define N_MAX 10000

int main() {
  int S, N;
  int price[N_MAX], needs[N_MAX];

  scanf("%d%d", &N, &S);
  for (int i = 0; i < N; i++)
    scanf("%d%d", &price[i], &needs[i]);

  int minPrice = price[0];
  long long totalCost = minPrice * needs[0];

  for (int i = 1; i < N; i++) {
    minPrice = min(minPrice + S, price[i]);
    totalCost += minPrice * needs[i];
  }

  printf("%lld\n", totalCost);
  return 0;
}
