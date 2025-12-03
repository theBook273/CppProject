#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
long long p, q, r;
vector<long long> a, pref;

int find_pos(int l, long long target) {
  int L = l, R = n;
  while (L <= R) {
    int m = (L + R) >> 1;
    long long sum = pref[m] - pref[l - 1];
    if (sum == target)
      return m;
    if (sum < target)
      L = m + 1;
    else
      R = m - 1;
  }
  return -1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> p >> q >> r;
  a.resize(n + 1);
  pref.resize(n + 1);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  long long res = 0;

  for (int x = 1; x <= n; x++) {
    int y = find_pos(x, p);
    if (y == -1) {
      continue;
    }

    int z = find_pos(y + 1, q);
    if (z == -1) {
      continue;
    }

    int w = find_pos(z + 1, r);
    if (w == -1) {
      continue;
    }

    res++;
  }

  cout << res;
}
