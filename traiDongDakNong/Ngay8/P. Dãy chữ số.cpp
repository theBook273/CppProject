#include <bits/stdc++.h>
#define int long long

using namespace std;

int p;
string s;

namespace sub1 {
int sol() { return s.size(); }
}; // namespace sub1

namespace sub2 {
int sol() {
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    if ((s[i] - '0') % 2 == 0) {
      res = i + 1;
    }
  }
  return res;
}
}; // namespace sub2

namespace fullSub {
int sol() {
  const int INF = 1e18;

  int n = s.size();
  if (n == 0) {
    return 0;
  }
  vector<int> prev_max(p, -INF);
  int res = 0;
  int zero_run = 0;
  for (int i = 0; i < n; i++) {
    int d = s[i] - '0';
    vector<int> cur_max(p, -INF);

    for (int r = 0; r < p; r++) {
      if (prev_max[r] != -INF) {
        int newR = (r * 10 % p + d) % p;
        cur_max[newR] = max(cur_max[newR], prev_max[r]);
      }
    }

    if (d != 0) {
      int newR = d % p;
      int val = zero_run - i;
      cur_max[newR] = max(cur_max[newR], val);
    }

    if (d == 0) {
      zero_run++;
    } else {
      zero_run = 0;
    }

    if (zero_run > res) {
      res = zero_run;
    }

    if (cur_max[0] != -INF) {
      int max_len = (i + 1) + cur_max[0];
      if (max_len > res) {
        res = max_len;
      }
    }

    prev_max = cur_max;
  }

  return res;
}
}; // namespace fullSub

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("digits.inp", "r", stdin);
  freopen("digits.out", "w", stdout);

  cin >> p >> s;
  int res = 0;

  if (p == 1) {
    res = sub1::sol();
  } else if (p == 2) {
    res = sub2::sol();
  } else {
    res = fullSub::sol();
  }
  cout << (res == 0 ? -1 : res);
}
