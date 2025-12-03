#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, x;
vector<int> a, pref;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  a.resize(n + 1);
  pref.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  cin >> m;
  while (m--) {
    cin >> x;
    x = upper_bound(pref.begin(), pref.end(), x - 1) - pref.begin();
    cout << (x > n ? -1 : x) << " ";
  }
}
