#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

bool add(int i, vector<int> &dem) {
  while (i) {
    dem[i % 10]++;
    if (dem[i % 10] > 2) {
      return 0;
    }
    i /= 10;
  }
  return 1;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, res = 0;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) {
    cin >> i;
  }

  int full = (1 << n);
  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }

    vector<int> cnt(10, 0);
    int sum = 0;
    bool flag = 1;
    for (auto i : pos) {
      if (add(a[i], cnt)) {
        sum += a[i];
      } else {
        flag = 0;
        break;
      }
    }
    if (flag) {
      res = max(res, sum);
    }
  }

  cout << res;
}
