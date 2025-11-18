#include <bits/stdc++.h>
#define int long long

using namespace std;

struct Edge {
  int from, to, len;
  bool operator<(const Edge &other) { return len < other.len; }
};

vector<int> dsu;
vector<Edge> edge;
vector<vector<char>> s;
int n, k;

int diff(vector<char> &a, vector<char> &b) {
  int diff = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    diff += (a[i] != b[i]);
  }
  return diff * 2;
}

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }
bool join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[x] = y;
    return 1;
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;

  dsu.resize(n + 1);
  iota(dsu.begin(), dsu.end(), 0);
  s.resize(n + 1, vector<char>(k));
  for (int i = 1; i <= n; i++) {
    for (auto &j : s[i]) {
      cin >> j;
    }
    edge.push_back({0, i, k});
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i != j) {
        edge.push_back({i, j, diff(s[i], s[j])});
      }
    }
  }

  int edCnt = 0, res = 0;
  sort(edge.begin(), edge.end());
  for (auto &[u, v, w] : edge) {
    if (join(u, v)) {
      edCnt++;
      res += w;
    }
    if (edCnt == (n)) {
      break;
    }
  }

  cout << res << "\n";
}
