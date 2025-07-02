#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  int n;
  cin >> n;

  vector<pair<int, int>> a(n);

  for (auto &i : a)
    cin >> i.first >> i.second;

  vector<int> b(1e6 + 5);
  int dau = 1e9, cuoi = 0;

  for (auto i : a) {
    b[i.first]++;
    b[i.second + 1]--;

    dau = min(dau, i.first);
    cuoi = max(cuoi, i.second);
  }

  vector<int> resolve(1e6 + 6);

  resolve[0] = b[0];

  for (int i = 1; i <= cuoi; i++) {
    resolve[i] = resolve[i - 1] + b[i];
  }

  int res = *max_element(resolve.begin(), resolve.begin() + cuoi + 1);

  int cnt = 0;

  for (int i = dau; i <= cuoi; i++) {
    if (resolve[i] == res)
      cnt++;
  }

  cout << res << "\n";
  cout << cnt;
}
