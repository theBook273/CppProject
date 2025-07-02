#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

signed main() {
  long long n;
  cin >> n;

  vector<pair<long long, long long>> a(n);

  for (auto &i : a)
    cin >> i.first >> i.second;

  vector<long long> b(1e6 + 5);
  long long dau = 1e9, cuoi = 0;

  for (auto i : a) {
    b[i.first]++;
    b[i.second + 1]--;

    dau = min(dau, i.first);
    cuoi = max(cuoi, i.second);
  }

  vector<long long> resolve(1e6 + 6);

  resolve[0] = b[0];

  for (long long i = 1; i <= cuoi; i++) {
    resolve[i] = resolve[i - 1] + b[i];
  }

  long long res = *max_element(resolve.begin(), resolve.begin() + cuoi + 1);

  long long cnt = 0;

  for (long long i = dau; i <= cuoi; i++) {
    if (resolve[i] == res)
      cnt++;
  }

  cout << res << "\n";
  cout << cnt;
}
