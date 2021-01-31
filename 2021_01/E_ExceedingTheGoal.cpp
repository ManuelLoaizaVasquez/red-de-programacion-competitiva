//E. Exceeding the Goal
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef unsigned long long Long;

Long f(Long n, Long s, Long k) {
  return n * s + n * (n - 1) / 2 * k;
}

Long Search(Long k, Long s, Long g) {
  Long l = 1;
  Long r = 44721;
  if (f(l, s, k) > g) return l;
  while (r - l > 1) {
    Long m = (l + r) / 2;
    if (f(m, s, k) > g) {
      r = m;
    } else {
      l = m;
    }
  }
  return r;
}

void Solve(void) {
  Long k, s, g;
  cin >> k >> s >> g;
  cout << Search(k, s, g) << '\n';
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
