#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e5;

vector<int> local, manager[MAXN + 5];
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("OFFOFF.INP", "r", stdin);
  freopen("OFFOFF.OUT", "w", stdout);

  cin >> n;
  local.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> local[i];
  }

  for (int u, i = 2; i <= n; i++) {
    cin >> u;
    manager[u].push_back(i);
  }
}
