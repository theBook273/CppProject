#include <bits/stdc++.h>
#include <unordered_map>
#define int long long

using namespace std;

const int MAXN = 3 * 1e4 + 5;
const int INF = 1e18;

struct Edge {
  int to, len;
};

vector<Edge> adj[MAXN];
vector<int> res;
int dis1[MAXN], disn[MAXN];
int n, m, shortest;

void dijis(int start, int dis[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  q.push({0, start});
  dis[start] = 0;

  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();

    if (du != dis[u]) {
      continue;
    }

    for (auto [v, w] : adj[u]) {
      if (dis[v] > dis[u] + w) {
        dis[v] = dis[u] + w;
        q.push({dis[v], v});
      }
    }
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  for (int u, v, w, i = 0; i < m; i++) {
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  for (int i = 1; i <= n; i++) {
    dis1[i] = disn[i] = INF;
  }

  dijis(1, dis1);
  dijis(n, disn);

  shortest = dis1[n];
  unordered_map<int, int> mp;

  for (int i = 1; i <= n; i++) {
    if (dis1[i] != INF && disn[i] != INF && dis1[i] + disn[i] == shortest) {
      mp[dis1[i]]++;
    }
  }

  for (int i = 2; i < n; i++) {
    if (dis1[i] != INF && disn[i] != INF && dis1[i] + disn[i] == shortest) {
      if (mp[dis1[i]] == 1) {
        continue;
      }
      res.push_back(i);
    } else {
      res.push_back(i);
    }
  }

  cout << res.size() << "\n";
  for (auto i : res) {
    cout << i << "\n";
  }
}
