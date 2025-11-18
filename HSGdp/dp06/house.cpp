#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a, minn;
int n;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  minn.resize(n);
  a.resize(n);

  for (auto &i : a) {
    cin >> i;
  }

  minn[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    minn[i] = min(minn[i + 1], a[i]);
  }

  int res = 0;
  for (int i = 0; i < n; i++) {
    res = max(res, a[i] - minn[i]);
  }
  cout << res << "\n";
}
