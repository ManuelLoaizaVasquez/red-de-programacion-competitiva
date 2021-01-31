//J. Johann's Function
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
using namespace std;

typedef long long Long;

void Solve(void) {
  Long n;
  scanf("%lld", &n);
  Long ans = (n * (n + 1) * (2 * n + 1) / 6LL + n * (n + 1) / 2LL) / 2LL;
  printf("%lld\n", ans);
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  scanf("%d", &t);
  while (t--) Solve();
  return 0;
}
