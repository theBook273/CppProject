#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool check(vector<int> a, int r, int tar) {
  int n = a.size(), k = 0;
  int mark = 0, id = 0;
  int lim = *max_element(a.begin(), a.end());

  while (mark < lim) {
    mark = 0;
    mark = a[id] + r + r;
    k++;
    id = (upper_bound(a.begin(), a.end(), mark) - a.begin());
  }

  return (k <= tar);
}

signed main() {
  int n, k;
  cin >> n >> k;

  vector<int> a(n);

  for (int &i : a)
    cin >> i;

  sort(a.begin(), a.end());

  int l = 1, r = 1e9;

  int res = 1e9;

  while (l <= r) {
    int m = (l + r) / 2;
    if (check(a, m, k)) {
      res = min(res, m);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << res;
}
