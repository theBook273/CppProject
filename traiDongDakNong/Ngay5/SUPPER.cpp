#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
vector<int> mp(1 << 20, 0);
vector<int> sum_sup(1 << 20, 0);

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;
  string temp;
  for (int i = 0; i < n; i++) {
    cin >> temp;

    int mask = 0;

    for (int j = 0; j < temp.size(); j++) {
      if (temp[j] == '1') {
        mask = mask | (1 << j);
      }
    }

    mp[mask]++;
  }

  int full = 1 << m;
  for (int mask = 0; mask < full; mask++) {
    sum_sup[mask] = mp[mask];
  }

  for (int bit = 0; bit < m; bit++) {
    for (int mask = 0; mask < full; mask++) {
      if (!(mask & (1 << bit))) {
        sum_sup[mask] += sum_sup[mask | (1 << bit)];
      }
    }
  }

  int ans = 0;
  for (int mask = 0; mask < full; mask++) {
    int f = mp[mask];
    if (f) {
      ans += f * (sum_sup[mask] - 1);
    }
  }

  cout << ans;
}
