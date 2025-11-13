#include <bits/stdc++.h>

using namespace std;

int board[2008][2008];

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    board[u][v] = 1;
    board[v][u] = 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << board[i][j] << " ";
    }
    cout << "\n";
  }
}
