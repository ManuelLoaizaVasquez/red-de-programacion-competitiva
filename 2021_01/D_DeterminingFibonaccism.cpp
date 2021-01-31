//D. Determining Fibonaccism
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
#include <unordered_set>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;

const int N = 1e4;
const Long MOD = (1LL << 31LL) - 1LL;

unordered_set<int> classes;

void Solve(void) {
  Long n;
  cin >> n;
  if (classes.count(n) == 0) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
}

void Precalculate(void) {
  classes.insert(0);
  classes.insert(1);
  Long f0 = 0;
  Long f1 = 1;
  Long f;
  for (int i = 2; i <= N; i++) {
    f = (f0 + f1) % MOD;
    classes.insert(f);
    f0 = f1;
    f1 = f;
  }
}

int main(void) {
  FAST_IO;
  Precalculate();
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
