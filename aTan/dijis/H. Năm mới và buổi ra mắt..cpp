#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e18;

struct Graph {
  int to, len;
};

vector<Graph> adj[MAXN];
vector<int> nhaH, nhaBH;
int disBH[MAXN], disH[MAXN], mark[MAXN];
int n, m, res;

void dijisk(vector<int> start, int dis[]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
  for (auto i : start) {
    q.push({0, i});
    dis[i] = 0;
  }

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
  for (int temp, i = 1; i <= n; i++) {
    cin >> temp;
    mark[i] = temp;
    (mark[i] == 0 ? nhaH.push_back(i) : nhaBH.push_back(i));
    disBH[i] = disH[i] = INF;
  }
  for (int u, v, w, i = 1; i <= m; i++) {
    cin >> u >> v >> w;
    adj[v].push_back({u, w});
  }

  dijisk(nhaBH, disBH);
  dijisk(nhaH, disH);

  for (int i = 1; i <= n; i++) {
    int res = (mark[i] == 0 ? disBH[i] : disH[i]);
    cout << (res == INF ? -1 : res) << "\n";
  }
}
