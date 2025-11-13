#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m, ans = 0;
  cin >> n >> m;
  char board[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string temp;
      for (int cnt = 0; cnt < 3 && j + cnt < m; cnt++) {
        temp.push_back(board[i][j + cnt]);
      }
      if (temp == "tan") {
        ans++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      string temp;
      for (int cnt = 0; cnt < 3 && i + cnt < n; cnt++) {
        temp.push_back(board[i + cnt][j]);
      }
      if (temp == "tan") {
        ans++;
      }
    }
  }

  cout << ans;
}
