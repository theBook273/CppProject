#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long a, b, c1, c2;
  int k;
  cin >> a >> b >> c1 >> c2 >> k;

  long long cmin = min(c1, c2);
  long long cmax = max(c1, c2);

  long long minv = LLONG_MAX, maxv = LLONG_MIN;

  for (int i = 0; i < k; i++) {
    long long x, y;
    cin >> x >> y;
    long long v = a * x + b * y;
    minv = min(minv, v);
    maxv = max(maxv, v);
  }

  if (maxv > cmin && minv < cmax)
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
