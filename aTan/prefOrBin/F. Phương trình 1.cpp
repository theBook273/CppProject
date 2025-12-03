#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, p, res = 0;
vector<int> a, pref;

bool valid(int x) {
  int l = x, r = n;
  while (l <= r) {
    int m((l + r) >> 1);
    int sum = pref[m] - pref[x - 1];
    if (sum == p) {
      return 1;
    } else if (sum > p) {
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> p;
  a.resize(n + 1, 0);
  pref.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  for (int i = 1; i <= n; i++) {
    if (valid(i)) {
      res++;
    }
  }

  cout << res;
}
