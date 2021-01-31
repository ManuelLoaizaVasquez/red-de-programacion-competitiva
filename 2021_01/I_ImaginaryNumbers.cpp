//I. Imaginary Numbers
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
using namespace std;

typedef long long Long;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(nullptr);
  Long a, b;
  while (cin >> a >> b) {
    if (a == 0 && b == 0) break;
    b %= 4;
    if (b > 1) a *= (-1);
    cout << a;
    if (a == 0) {
      cout << '\n';
      continue;
    }
    if (b & 1) cout << "i";
    cout << '\n';
  }
  return 0;
}
