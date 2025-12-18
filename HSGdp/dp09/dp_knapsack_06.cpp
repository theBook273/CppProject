#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e6;

int a, b, t;
vector<bool> dp1(N + 1, 0);
vector<bool> dp2(N + 1, 0);

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("FRUIT.INP", "r", stdin);
  freopen("FRUIT.OUT", "w", stdout);

  cin >> t >> a >> b;

  dp1[0] = 1;
  for (int i = 0; i <= t; i++) {
    if (dp1[i]) {
      if (i + a <= t) {
        dp1[i + a] = 1;
      }
      if (i + b <= t) {
        dp1[i + b] = 1;
      }
    }
  }

  for (int i = 2; i <= t; i++) {
    if (dp1[i]) {
      dp2[i / 2] = 1;
    }
  }

  for (int i = 0; i <= t; i++) {
    if (dp2[i]) {
      if (i + a <= t) {
        dp2[i + a] = 1;
      }
      if (i + b <= t) {
        dp2[i + b] = 1;
      }
    }
  }

  for (int i = t; i >= 0; i--) {
    if (dp1[i] || dp2[i]) {
      cout << i;
      return 0;
    }
  }
}
