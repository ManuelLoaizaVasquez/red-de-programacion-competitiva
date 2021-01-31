//B. Breaking Vacations
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const int N = 1e4;
const int K = 1e2 + 5;
const Long INF = 1e9;

Pair days[N];
Long dp[N][K], prefix[N];
bool is_done[N][K];

Long DP(int i, int rem) {
  if (rem <= 0) return (i < 0) ? 0 : prefix[i];
  if (i < 0) return -INF;
  if (is_done[i][rem]) return dp[i][rem];
  is_done[i][rem] = true;
  dp[i][rem] = max(days[i].second + DP(i - 1, rem), DP(i - 1, rem - days[i].first));
  return dp[i][rem];
}

void Initialize(int n, int k) {
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= k; j++)
      is_done[i][j] = false;
}

void Solve(void) {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    Long a, b, c;
    cin >> a >> b >> c;
    days[i].first = a;
    days[i].second = max(b, c);
  }
  prefix[0] = days[0].second;
  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + days[i].second;
  }
  Initialize(n, k);
  Long ans = DP(n - 1, k);
  if (ans >= 0) {
    cout << ans << '\n';
  } else {
    cout << "NO SOLUTION" << '\n';
  }
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  while (t--) Solve();
  return 0;
}
