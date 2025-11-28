#include <bits/stdc++.h>
#define ll long long

using namespace std;

int n, q;

ll getalt(int l, int r, vector<ll> &alt) {
  ll res = alt[r] - alt[l - 1];
  if (l % 2 == 0) {
    res = -res;
  }
  return res;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("rating.inp", "r", stdin);
  freopen("rating.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> q;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }

    vector<ll> alt(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pref[i] = pref[i - 1] + a[i];
      if (i % 2 == 1) {
        alt[i] = alt[i - 1] + a[i];
      } else {
        alt[i] = alt[i - 1] - a[i];
      }
    }

    while (q--) {
      ll x;
      int l, r;
      cin >> x >> l >> r;

      if (x < 0) {
        x = abs(a[l] - x);
        l++;
      }

      if (l > r) {
        cout << x << "\n";
        continue;
      }

      long long target = x + pref[l - 1];
      auto it = upper_bound(pref.begin() + l, pref.begin() + r + 1, target - 1);
      int pos = (it - pref.begin()) - 1;

      ll sumleft = 0;
      if (pos >= l) {
        sumleft = pref[pos] - pref[l - 1];
      }
      ll xp = x - sumleft;

      int m = r - pos;
      ll altSum = getalt(pos + 1, r, alt);

      ll ans;
      if (m % 2 == 0) {
        ans = xp - altSum;
      } else {
        ans = altSum - xp;
      }

      cout << ans << "\n";
    }
  }
}
