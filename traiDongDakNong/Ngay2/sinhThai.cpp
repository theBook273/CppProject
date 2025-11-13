#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6 + 5;

struct Edge {
  int to, len;
};

vector<Edge> adj[MAXN];
vector<int> dis;

void dijis(int start) {
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
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  vector<char> s(n + 1);
  dis.resize(n + 1, LLONG_MAX);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    int u = i - 1;
    int v = i;
    adj[u].push_back({v, a});
    if (u != 0) {
      adj[v].push_back({u, b});
    }
  }

  vector<int> last(256, -1);

  for (int i = 1; i <= n; i++) {
    if (last[s[i]] != -1) {
      int u = last[s[i]];
      adj[u].push_back({i, c});
      adj[i].push_back({u, d});
    }
    last[s[i]] = i;
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << i << ": \n";
  //   for (auto [x, y] : adj[i]) {
  //     cout << x << " " << y << "\n";
  //   }
  //   cout << "---------\n";
  // }

  dijis(1);
  cout << dis[n];
}
