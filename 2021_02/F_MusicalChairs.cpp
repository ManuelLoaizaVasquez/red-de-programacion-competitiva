//F. Musical Chairs
//https://redprogramacioncompetitiva.com/contests/2021/02/team/run.php
#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef long double Double;
typedef unsigned long long ULong;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long INF = 1e18;
const Double EPS = 1e-9;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    p[i] = i;
  }
  int cnt = n;
  int pos = 0;
  while (cnt > 1) {
    pos = (pos + a[pos] - 1) % cnt;
    for (int j = pos; j < cnt - 1; j++) {
      a[j] = a[j + 1];
      p[j] = p[j + 1];
    }
    cnt--;
    if (pos == cnt) pos = 0;
  }
  cout << p[pos] + 1 << '\n';
  return 0;
}