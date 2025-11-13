#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

const int MAXN = 2000 + 273;

int n, m, k, ans = LLONG_MIN;
int a[MAXN][MAXN];
int preRow[MAXN][MAXN], preDia[MAXN][MAXN], preCol[MAXN][MAXN];
int dp[MAXN][MAXN];

signed main() {
  cin.tie()->sync_with_stdio(0);
  // freopen("TRIANGLE.INP", "r", stdin);
  // freopen("TRIANGLE.OUT", "w", stdout);
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      int tong = 0;
      if (j > 0) {
        tong = preRow[i][j - 1];
      }
      preRow[i][j] = tong + a[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      preDia[i][j] = a[i][j];
      if (i > 0 && j > 0) {
        preDia[i][j] += preDia[i - 1][j - 1];
      }
    }
  }

  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      int tong = 0;
      if (i > 0) {
        tong = preCol[i - 1][j];
      }
      preCol[i][j] = tong + a[i][j];
    }
  }

  for (int i = 0; i + k - 1 < n; i++) {
    for (int dem = 0; dem < k; dem++) {
      dp[i][0] += preRow[i + dem][dem];
    }
  }

  for (int i = 0; i + k - 1 < n; i++) {
    for (int j = 1; j + k - 1 < m; j++) {
      int toSub = preCol[i + k][j] - (i ? preCol[i - 1][j] : 0);
      int toAdd = preDia[i + k][j + k] - (i && j ? preDia[i - 1][j - 1] : 0);
      dp[i][j] = dp[i][j - 1] - toSub + toAdd;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
}
