#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 1e6;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  int dp1 = 1;
  int dp2 = 2;
  int dp3 = 4;
  int tong = 0;
  for (int i = 4; i <= n; i++) {
    tong = dp1 % m + dp2 % m + dp3 % m;
    dp1 = dp2, dp2 = dp3, dp3 = tong;
  }
  cout << dp3 % m << "\n";
}
