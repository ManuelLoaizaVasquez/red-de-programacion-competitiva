//K. k-Uniform Array
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <algorithm>
#include <iostream>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
using namespace std;

typedef long long Long;
typedef pair<Long, Long> Pair;

const int N = 1e5;
const int INF = 1e6;

vector<int> pos[N];

struct Consulta {
  int l, r;
  bool operator < (const Consulta& other) const{
    return r < other.r;
  }
};

void Compress(vector<int>& a) {
  int n = a.size();
  n--;
  vector<pair<int, int>> pairs;
  for (int i = 1; i <= n; i++) pairs.push_back({a[i], i});
  sort(pairs.begin(), pairs.end());
  int nxt = 0;
  for (int i = 0; i < n; i++) {
    if (i > 0 && pairs[i].first != pairs[i - 1].first) nxt++;
    a[pairs[i].second] = nxt;
  }
}

struct FenwickTree {
  int tree[N + 1];
  void Update(int i, int delta) {
    while (i <= N) {
      tree[i] += delta;
      i += (i & -i);
    }
  }
  int Query(int i) {
    int ans = 0;
    while (i > 0) {
      ans += tree[i];
      i -= (i & -i);
    }
    return ans;
  }
} ft;

void Solve(void) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];
  Compress(a);
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    pos[a[i]].push_back(i);
  }
  // Construyo las consultas
  vector<Consulta> q;
  for (int i = 0; i < n; i++) {
    int len = pos[i].size();
    for (int j = 0; j + k <= len; j++) {
      q.push_back({pos[i][j], pos[i][j + k - 1]});
    } 
  }
  sort(q.begin(), q.end());
  vector<int> last(n, 0);
  int current = 0;
  for (int i = 0; i < q.size(); i++) {
    while (current < q[i].r) {
      current++;
      if (last[a[current]] != 0) ft.Update(last[a[current]], -1);
      ft.Update(current, 1);
      last[a[current]] = current;
    }
    int tmp = ft.Query(q[i].r) - ft.Query(q[i].l - 1) - 1;
    ans = min(ans, tmp);
  }
  if (ans == INF) {
    cout << -1 << '\n';
  } else {
    cout << ans << '\n';
  }
}


int main(void) {
  FAST_IO;
  int t = 1;
  //cin >> t;
  while (t--) Solve();
  return 0;
}
