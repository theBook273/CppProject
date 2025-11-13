#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1000000007;

void solve() {
  int l1, h1, l2, h2, l3, h3, l4, h4, n;
  cin >> l1 >> h1 >> l2 >> h2 >> l3 >> h3 >> l4 >> h4 >> n;
  int temp = 0;
  int cnt = 0;
  for (int i = l1; i <= h1; i++) {
    for (int j = l2; j <= h2; j++) {
      for (int k = l3; k <= h3; k++) {
        for (int h = l4; h <= h4; h++) {
          temp = i + j + k + h;
          if (temp == n) {
            cnt++;
            cnt %= MOD;
          }
        }
      }
    }
  }
  cout << cnt % MOD;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
