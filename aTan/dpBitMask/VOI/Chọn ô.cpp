#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

const int oo = 1e18;

string bin(int x) {
  string s;
  for (int i = 0; i < 4; i++) {
    char ins = '0';
    if ((x >> i) & 1) {
      ins = '1';
    }
    s.push_back(ins);
  }
  return s;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> valid = {0};

  int full = (1 << 4);
  for (int mask = 1; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < 4; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    if (pos.size() <= 2 && pos[0] + 1 != pos[1]) {
      valid.push_back(mask);
    }
  }

  // for (auto i : valid) {
  //   cout << i << endl;
  // }

  int n;
  cin >> n;

  vector<vector<int>> a(4, vector<int>(n));

  int temp = -oo;

  for (auto &i : a) {
    for (auto &j : i) {
      cin >> j;
      temp = max(temp, j);
    }
  }

  if (temp < 0) {
    cout << temp;
    return 0;
  }

  vector<vector<int>> dp(n, vector<int>(20, -oo));

  for (int mask : valid) {
    vector<int> pos;
    for (int i = 0; i < 4; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }
    int sum = 0;
    for (auto i : pos) {
      sum += a[i][0];
    }
    dp[0][mask] = sum;
  }

  for (int i = 1; i < n; i++) {
    for (auto mask : valid) {
      vector<int> pos;
      for (int x = 0; x < 4; x++) {
        if ((mask >> x) & 1) {
          pos.push_back(x);
        }
      }
      int sum = 0;
      for (auto j : pos) {
        sum += a[j][i];
      }
      for (auto pmask : valid) {
        if (!(mask & pmask)) {
          dp[i][mask] = max(dp[i][mask], dp[i - 1][pmask] + sum);
        }
      }
    }
  }

  int res = -oo;

  for (auto mask : valid) {
    res = max(res, dp[n - 1][mask]);
  }

  cout << res;
}
