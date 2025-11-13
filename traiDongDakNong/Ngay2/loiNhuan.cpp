#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e3 + 5;

const pair<int, int> moveSet[] = {{0, -1}, {-1, 0}, {-1, 1}, {1, -1}};
int board[MAXN][MAXN], dp[MAXN][MAXN];
int n;

signed main() {
  cin.tie()->sync_with_stdio(0);

  // freopen("test.inp", "r", stdin);
  // freopen("test.out", "w", stdout);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> board[i][j];
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    res += board[1][i];
  }
  for (int i = 2; i <= n; i++) {
    res += board[i][1];
  }

  cout << res;
}
