#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
vector<int> a, pref;

int look(int x) {
  int l = 1, r = x;
  int num = -1;
  int target = pref[x] - k;
  while (l <= r) {
    int m((l + r) >> 1);
    if (pref[m - 1] >= target) {
      num = m;
      r = m - 1;
    } else {
      l = m + 1;
    }
  }
  return num;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;

  a.resize(n + 1, 0);
  pref.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] + a[i];
  }

  int res = 0;

  for (int i = 1; i <= n; i++) {
    int sum = look(i);
    if (sum != -1) {
      res += i - sum + 1;
    }
  }

  cout << res;
}
