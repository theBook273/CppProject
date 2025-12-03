#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n + 1), maxF(n + 1), maxG(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  maxF[1] = a[1] + 1;

  for (int i = 2; i <= n; i++) {
    maxF[i] = max(maxF[i - 1], a[i] + i);
  }

  maxG[n] = a[n] - n;
  for (int i = n - 1; i >= 1; i--) {
    maxG[i] = max(maxG[i + 1], a[i] - i);
  }

  int res = 0;
  for (int i = 2; i < n; i++) {
    res = max(res, maxF[i - 1] + a[i] + maxG[i + 1]);
  }

  cout << res;
}
