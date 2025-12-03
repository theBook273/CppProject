#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a, tang, giam;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  a.resize(n);
  tang.resize(n, 1);
  giam.resize(n, 1);

  for (auto &i : a) {
    cin >> i;
  }

  for (int i = 1; i < n - 1; i++) {
    if (a[i] >= a[i - 1]) {
      tang[i] = max(tang[i], tang[i - 1] + 1);
    }
  }

  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] <= a[i]) {
      giam[i] = max(giam[i], giam[i + 1] + 1);
    }
  }

  int res = 1;
  for (int i = 0; i < n; i++) {
    res = max(res, giam[i] + tang[i] - 1);
  }

  cout << res << "\n";
}
