#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> pref(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    pref[i] = pref[i - 1] + a[i];
  }

  for (int i = 1; i <= n; ++i) {
    long long ans = a[i] * (2LL * i - n - 2LL) + pref[n] - 2LL * pref[i - 1];
    cout << ans << " ";
  }
}
