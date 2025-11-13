#include <bits/stdc++.h>
#include <climits>
#define int long long

using namespace std;

const int MAXN = 2 * 1e5 + 5;

int in[MAXN], out[MAXN], pos[MAXN], val[MAXN];
vector<int> adj[MAXN];
int n, q, timer = 0;

void setup(int u, int p) {
  in[u] = ++timer;
  pos[timer] = u;
  for (auto v : adj[u]) {
    if (v != p) {
      setup(v, u);
    }
  }
  out[u] = timer;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  setup(1, 1);
  cin >> q;
  int type, a, b, res = LLONG_MIN;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> a >> b;
      for (int i = in[a]; i <= out[a]; i++) {
        val[pos[i]] += b;
      }
    } else {
      cin >> a;
      res = LLONG_MIN;
      for (int i = in[a]; i <= out[a]; i++) {
        res = max(res, val[pos[i]]);
      }
      cout << res << "\n";
    }
  }
}
