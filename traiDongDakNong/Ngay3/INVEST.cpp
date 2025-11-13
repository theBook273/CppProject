#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, q, day1, day2, shop1, shop2, tong = 0;
vector<vector<int>> board, prefix;

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  board.resize(m + 1, vector<int>(n + 1));
  prefix.resize(m + 1, vector<int>(n * 4 + 5));
  for (int i = 1; i <= n; i++) {
    cin >> board[1][i];
  }

  for (int j = 2; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      board[j][i] = board[j - 1][board[1][i]];
    }
  }

  for (int j = 1; j <= m; j++) {
    prefix[j][1] = board[j][1];
    for (int i = 2; i <= n; i++) {
      prefix[j][i] = prefix[j][i - 1] + board[j][i];
    }
  }

  cin >> q;
  while (q--) {
    tong = 0;
    cin >> day1 >> day2 >> shop1 >> shop2;
    for (int i = day1; i <= day2; i++) {
      tong += prefix[i][shop2] - prefix[i][shop1 - 1];
    }
    cout << tong << "\n";
  }
}
