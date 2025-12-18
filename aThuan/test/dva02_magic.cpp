#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e5;
const int W = 3000;
const int oo = 1e18;

int n, x;

vector<pair<int, int>> wands;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> x;
  for (int w, l, c, i = 0; i < n; i++) {
    cin >> w >> l >> c;
    vector<int> vals;
    while (l > 0) {
      vals.push_back(l);
      l -= c;
    }

    int m = vals.size();
    int start = 0;
    int k = 1;

    while (m) {
      int take = min(m, k);

      int first = vals[start];
      int sumVal = first * take - c * (take * (take - 1) / 2);

      int weight = w * take;
      if (weight <= x) {
        wands.push_back({weight, sumVal});
      }
    }
  }

  vector<int> dp(x + 1, -oo);
  dp[0] = 0;
  for (auto &p : wands) {
    int w = p.first, v = p.second;

    for (int j = x; j >= w; j--) {
      dp[j] = max(dp[j], dp[j - w] + v);
    }
  }

  cout << *max_element(dp.begin(), dp.end());
}
