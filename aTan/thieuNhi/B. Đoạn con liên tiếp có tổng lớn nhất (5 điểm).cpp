#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

int kaden(vector<int> &a) {
  int best = LLONG_MIN, cur = 0;
  for (int &i : a) {
    cur = max(i, cur + i);
    best = max(best, cur);
  }
  return best;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("SUB.INP", "r", stdin);
  freopen("SUB.OUT", "w", stdout);

  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0) {
      b[i] = a[i];
      c[i] = -a[i];
    } else {
      b[i] = -a[i];
      c[i] = a[i];
    }
  }

  cout << max(kaden(b), kaden(c));
}
