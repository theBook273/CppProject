#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> fibo(1000 + 1, 0);

void solve() {
  int u, v;
  cin >> u >> v;

  int len = v - u + 1;
  if (len >= 32) {
    cout << len / 16 * 16 << "\n";
  } else {
    u--, v--;
    int res = -1;
    for (int i = u; i < v; i++) {
      if (fibo[(i % 16)] == fibo[(i + 1) % 16]) {
        res = 2;
      }
    }
    cout << res << "\n";
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  fibo[0] = 1;
  fibo[1] = 2;
  for (int i = 2; i <= 15; i++) {
    fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 7;
  }

  while (t--) {
    solve();
  }
}
