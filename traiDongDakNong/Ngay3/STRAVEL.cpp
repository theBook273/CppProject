#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 3e3 + 5;
const int MOD = 1e9 + 7;
vector<int> res;
int n;

namespace sub1 {

vector<int> adj[MAXN];
set<int> se;

void solve(int u, int p) {
  se.insert(u);
  if ((int)se.size() == n) {
    res[u]++;
    res[u] %= MOD;
    return;
  }
  for (auto v : adj[u]) {
    if (v != p && !se.count(v)) {
      se.insert(v);
      solve(v, u);
      se.erase(v);
    }
  }
}

void mainSol() {
  char temp;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    if (temp == '>') {
      for (int j = i + 1; j <= n; j++) {
        adj[i].push_back(j);
      }
    } else if (temp == '<') {
      for (int j = 1; j < i; j++) {
        adj[i].push_back(j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    se.clear();
    solve(i, i);
  }

  for (int i = 1; i <= n; i++) {
    cout << res[i] << "\n";
  }
}
} // namespace sub1

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  res.resize(n + 1);
  sub1::mainSol();
}
