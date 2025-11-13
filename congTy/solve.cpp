#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, q;

int chenhLech(vector<int> &a) {
  vector<int> dp(n, 0);

  for (int i = 0; i < n; i++) {
    int minx = a[i], maxx = a[i];
    for (int j = i; j >= 0; j--) {
      maxx = max(maxx, a[j]);
      minx = min(minx, a[j]);
      int prev = (j > 0 ? dp[j - 1] : 0);
      dp[i] = max(dp[i], prev + (maxx - minx));
    }
  }

  return dp.back();
}

signed main() {
  freopen("GROUP.INP", "r", stdin);
  freopen("GROUP.OUT", "w", stdout);
  cin.tie()->sync_with_stdio(0);

  cin >> n >> q;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  while (q--) {
    int que;
    cin >> que;
    if (que == 2) {
      cout << chenhLech(a) << "\n";
    } else {
      int l, r, x;
      cin >> l >> r >> x;
      l--;
      r--;
      for (int i = l; i <= r; i++) {
        a[i] += x;
      }
    }
  }
}
