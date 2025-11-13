#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2 * 1e5 + 273;

int in[MAXN], out[MAXN], pos[MAXN], val[MAXN];
vector<int> adj[MAXN];
int n, q, times = 0;

void setup(int u, int p) {
  in[u] = ++times;
  pos[times] = u;
  for (auto v : adj[u]) {
    if (v != p)
      setup(v, u);
  }
  out[u] = times;
}

int calc(int s) {
  int tong = 0;
  for (int i = in[s]; i <= out[s]; i++) {
    tong += val[pos[i]];
  }
  return tong;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;

  for (int i = 1; i <= n; i++) {
    cin >> val[i];
  }

  for (int u, v, i = 1; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  setup(1, 1);
  int type, a, b;
  while (q--) {
    cin >> type;
    if (type == 1) {
      cin >> a >> b;
      val[a] = b;
    } else {
      cin >> a;
      cout << calc(a) << "\n";
    }
  }
}
