#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18;
const int N = 3e5;

vector<pair<int, int>> adj;
vector<int> tong, deg, leaves;
unordered_map<int, vector<int>> road;
vector<bool> active;
multiset<int> minLeaf;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  adj.resize(n + 1, {1, 0});
  tong.resize(n + 1, 0);
  active.resize(n + 1, 0);
  deg.resize(n + 1, 0);

  for (int u, w, i = 2; i <= n; i++) {
    cin >> u >> w;
    adj[i] = {u, w};
    deg[u]++;
  }

  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      leaves.push_back(i);
      active[i] = 1;
    }
  }

  for (auto i : leaves) {
    int temp = i;
    while (adj[temp].first != temp) {
      tong[i] += adj[temp].second;
      road[temp].push_back(i);
      temp = adj[temp].first;
    }
    minLeaf.insert(tong[i]);
  }

  while (q--) {
    int x;
    cin >> x;
    for (int i : road[x]) {
      if (active[i]) {
        active[i] = 0;
        minLeaf.erase(minLeaf.find(tong[i]));
      }
    }
    if (minLeaf.empty()) {
      cout << -1 << "\n";
    } else {
      cout << *minLeaf.begin() << "\n";
    }
  }
}
