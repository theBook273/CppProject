#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a;
int n;

bool check(int x, int y) {
  for (int i = 1; i <= n; i++) {
    if (a[i] != (x * i + y * (n - i + 1)))
      return 0;
  }
  return 1;
}

void solve() {
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int y = (2 * a[1] - a[2]) / (n + 1);
  int x = a[1] - n * y;

  x = max(x, 0LL);
  y = max(y, 0LL);

  if (check(x, y)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
