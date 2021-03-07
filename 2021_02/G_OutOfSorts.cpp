//G. Out of Sorts
//https://redprogramacioncompetitiva.com/contests/2021/02/team/run.php
#include <bits/stdc++.h>
#include <unistd.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Long n, m, a, c, x0;
  cin >> n >> m >> a >> c >> x0;
  vector<Long> x(n + 1);
  x[0] = x0;
  for (int i = 1; i <= n; i++) {
    x[i] = (((a % m) * (x[i - 1] % m)) % m + c % m) % m;
  }
  Long ans = 0;
  for (int i = 1; i <= n; i++) {
    Long target = x[i];
    Long low = 1;
    Long high = n;
    while (true) {
      if (low > high) break;
      if (low == high) {
        if (x[low] == target) {
          ans++;
        }
        break;
      }
      Long mid = (low + high) / 2;
      if (x[mid] == target) {
        ans++;
        break;
      }
      if (x[mid] < target) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}

