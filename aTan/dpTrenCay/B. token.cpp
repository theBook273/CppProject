#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 5;

int parent[MAXN], token[MAXN];
vector<int> adj[MAXN];

int dfs(int u) {
  int sum = 1;
  for (int v : adj[u]) {
    int sub = dfs(v);
    token[u] += token[v] + sub;
    sum += sub;
  }
  token[u] += 1;
  return sum;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  parent[1] = 1;
  for (int u, i = 2; i <= n; i++) {
    cin >> u;
    parent[i] = u;
    adj[u].push_back(i);
  }

  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << token[i] << " ";
  }
}
