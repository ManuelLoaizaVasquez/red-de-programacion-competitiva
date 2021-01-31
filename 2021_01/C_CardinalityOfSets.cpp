//C. Cardinality of Sets
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  int n, m;
  while (cin >> n >> m) {
    if (n == 0 && m == 0) break;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int intersection = 0;
    for (int i = 0; i < m; i++) {
      int b;
      cin >> b;
      auto it = lower_bound(a.begin(), a.end(), b);
      if (it != a.end() && *it == b) intersection++;
    }
    cout << n - intersection << " " <<
      intersection << " " <<
      m - intersection << " " <<
      n + m - intersection << '\n';
  }
  return 0;
}
