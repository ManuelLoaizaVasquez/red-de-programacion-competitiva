//A. Retribution
//https://redprogramacioncompetitiva.com/contests/2021/02/team/problem.php
#include <bits/stdc++.h>
#include <unistd.h>
#define debug(x) cout << #x << " = " << x << endl
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
Long random(Long a, Long b) { return uniform_int_distribution<Long> (a, b) (rng); }

struct Pt {
  Long x, y;
  void Read(void) {
    cin >> x >> y;
  }
};

Long Square(const Pt& p1, const Pt& p2) {
  Long dx = p1.x - p2.x;
  Long dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

Double Distance(const Pt& p1, const Pt& p2) {
  Long dx = p1.x - p2.x;
  Long dy = p1.y - p2.y;
  return sqrt((Double) (dx * dx + dy * dy));
}

struct Trio {
  Long d2;
  Long i;
  Long j;
  bool operator < (const Trio& o) const {
    if (d2 != o.d2) return d2 < o.d2;
    if (i != o.i) return i < o.i;
    return j < o.j;
  }
};

vector<int> GetAssignment(const vector<Pt>& p, const vector<Pt>& q) {
  int n = p.size();
  int m = q.size();
  vector<int> ans(n);
  vector<bool> p_used(n, false);
  vector<bool> q_used(m, false);
  vector<Trio> t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      t.push_back({Square(p[i], q[j]), i, j});
    }
  }
  sort(t.begin(), t.end());
  for (int pos = 0; pos < (int) t.size(); pos++) {
    if (!p_used[t[pos].i] && !q_used[t[pos].j]) {
      ans[t[pos].i] = t[pos].j;
      p_used[t[pos].i] = q_used[t[pos].j] = true;
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  Long n, m, p;
  cin >> n >> m >> p;
  vector<Pt> points(n);
  for (int i = 0; i < n; i++) points[i].Read();
  vector<Pt> tars(m);
  for (int i = 0; i < m; i++) tars[i].Read();
  vector<Pt> feathers(p);
  for (int i = 0; i < p; i++) feathers[i].Read();
  vector<int> t = GetAssignment(points, tars);
  vector<int> f = GetAssignment(points, feathers);
  Double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += Distance(points[i], tars[t[i]]) + Distance(points[i], feathers[f[i]]);
  } 
  cout << fixed << setprecision(12) << ans << '\n';
  return 0;
}