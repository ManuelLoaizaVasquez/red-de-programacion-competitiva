//H. Hidden Professions
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int N = 5e4;  // total de caracteres + 1
const int ALPHABET = 26;

struct Trie {
  int trie[N][ALPHABET], id[N];
  int nodes = 1;
  Trie(void) { for (int i = 0; i < N; i++) id[i] = -2; }
  void Clear(void) {
    for (int i = 0; i < nodes; i++) {
      id[i] =  -2;
      for (int j = 0; j < ALPHABET; j++) trie[i][j] = 0;
    }
    nodes = 1;
  }
  void AddWord(const string& s, int current_id) {
    int n = s.size();
    int u = 0;
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (trie[u][c] == 0) trie[u][c] = nodes++;
      u = trie[u][c];
      if (id[u] == -2) {
        id[u] = current_id;
      } else if (id[u] != current_id) {
        id[u] = -1;
      }
    }
  }
  int IsPrefix(const string& s) {
    int n = s.size();
    int u = 0;
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (trie[u][c] == 0) return -1;
      u = trie[u][c];
    }
    return id[u];
  }
} trie;


void Solve(void) {
  int p, r;
  cin >> p >> r;
  trie.Clear();
  for (int i = 0; i < p; i++) {
    int cnt;
    cin >> cnt;
    for (int j = 0; j < cnt; j++) {
      string s;
      cin >> s;
      trie.AddWord(s, i);
    }
  }
  unordered_set<int> tags;
  for (int i = 0; i < r; i++) {
    tags.clear();
    int titles;
    cin >> titles;
    for (int j = 0; j < titles; j++) {
      string s;
      cin >> s;
      int tag = trie.IsPrefix(s);
      if (tag != -1) tags.insert(tag);
    }
    cout << tags.size() << '\n';
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
