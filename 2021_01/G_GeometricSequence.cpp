//G. Geometric Sequence
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
#include <vector>
using namespace std;

typedef long long Long;

const Long MOD = 1e9;

Long Add(Long a, Long b) {
  return (a + b) % MOD;
}

Long Mul(Long a, Long b) {
  return (a * b) % MOD;
}

Long FastPow(Long a, Long b) {
  Long ans = 1LL;
  while (b > 0) {
    if (b & 1) ans = Mul(ans, a);
    b >>= 1;
    a = Mul(a, a);
  }
  return ans;
}

void Solve(void) {
  Long k, q, b;
  cin >> k >> q;
  vector<Long> a(k);
  for (int i = 0; i < k; i++) cin >> a[i];
  while (q--) {
    cin >> b;
    if (a[b % k] == 0) {
      cout << 0 << '\n';
      continue;
    }
    Long exponent = b / k + 1;
    Long ans = FastPow(abs(a[b % k]), exponent);
    if (a[b % k] < 0 && exponent & 1) ans *= -1;
    ans = Add(ans, MOD);
    cout << ans << '\n';
  }
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) Solve();
  return 0;
}
