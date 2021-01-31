//F. Farthest Cell in a Maze
//https://redprogramacioncompetitiva.com/contests/2021/01/team/problem.php
#include <deque>
#include <iostream>
#include <utility>
#include <vector>
#define FAST_IO ios::sync_with_stdio(0);cin.tie(NULL)
#define x first
#define y second
using namespace std;

typedef long long Long;
typedef pair<int, int> Pair;

const int N = 1e3;
const int INF = 1e9;
const Pair not_pair = {-1, -1};

int h, w;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
char chr[4] = {'D', 'L', 'R', 'U'};
string s[N];
Pair origin;
string answer;

bool IsValid(const Pair& p) {
  return 0 <= p.x && p.x < h && 0 <= p.y && p.y < w && s[p.x][p.y] == '.';
}

struct Graph {
  Pair adj[N][N][4];
  pair<Pair, int> parent[N][N];
  int d[N][N];  // BFS
  bool is_terminal[N][N], is_visited[N][N];
  
  void Clear(void) {
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        for (int k = 0; k < 4; k++) adj[i][j][k] = not_pair;
        is_terminal[i][j] = false;
        is_visited[i][j] = false;
      }
    }
  }

  void AddEdge(Pair u) {
    Pair p = parent[u.x][u.y].first;
    int c = parent[u.x][u.y].second;
    adj[p.x][p.y][c] = u;
  }

  void BFS(const Pair& s) {
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        d[i][j] = INF;
    d[s.x][s.y] = 0;
    deque<Pair> tour;
    tour.push_back(origin);
    while (!tour.empty()) {
      Pair u = tour.front();
      tour.pop_front();
      for (int i = 0; i < 4; i++) {
        Pair nxt = {u.x + dx[i], u.y + dy[i]};
        if (IsValid(nxt) && d[nxt.x][nxt.y] == INF) {
          d[nxt.x][nxt.y] = d[u.x][u.y] + 1;
          parent[nxt.x][nxt.y] = {u, i};
          tour.push_back(nxt);
        }
      }
    }
  }

  void Reconstruct(Pair u) {
    if (u == origin || is_visited[u.x][u.y]) return;
    AddEdge(u);
    is_visited[u.x][u.y] = true;
    Reconstruct(parent[u.x][u.y].first);
  }

  void DFS(Pair u, Pair p) {
    if (is_terminal[u.x][u.y]) cout << answer << '\n';
    for (int i = 0; i < 4; i++) {
      Pair v = adj[u.x][u.y][i];
      if (v != not_pair && v != p) {
        answer += chr[i];
        DFS(v, u);
        answer.pop_back();
      }
    }
  }
} g;


void Solve(void) {
  cin >> w >> h;
  for (int i = 0; i < h; i++) cin >> s[i];
  // Encuentro la posicion del profesor
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s[i][j] == '@') {
        origin.x = i;
        origin.y = j;
        break;
      }
    }
  }
  g.Clear();
  // Hallo las distancias minimas desde el origen hacia todos los nodos
  // y luego hallo la mayor distancia minima
  g.BFS(origin);
  int mx = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (g.d[i][j] < INF)
        mx = max(mx, g.d[i][j]);
  // Cuento cuantos tienen dicha maxima distancia minima.
  // Aquellos nodos que cumplan con la condicion los marcare como terminales y
  // la rama del BFS tree que los descubrio.
  int cnt = 0;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (g.d[i][j] == mx) {
        cnt++;
        g.is_terminal[i][j] = true;
        g.Reconstruct({i, j});
      }
    }
  }
  cout << cnt << " " << mx << '\n';
  g.DFS(origin, {-1, -1});
}

int main(void) {
  FAST_IO;
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cout << "Case " << i << ":" << '\n';
    Solve();
  }
  return 0;
}
