#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool check(vector<long long> a, long long r, long long tar) {
  long long n = a.size(), k = 0;
  long long mark = 0, id = 0;
  long long lim = *max_element(a.begin(), a.end());

  while (mark < lim) {
    mark = 0;
    mark = a[id] + r + r;
    k++;
    id = (upper_bound(a.begin(), a.end(), mark) - a.begin());
  }

  return (k <= tar);
}

signed main() {
  long long n, k;
  cin >> n >> k;

  vector<long long> a(n);

  for (long long &i : a)
    cin >> i;

  sort(a.begin(), a.end());

  long long l = 1, r = 1e9;

  long long res = 1e9;

  while (l <= r) {
    long long m = (l + r) / 2;
    if (check(a, m, k)) {
      res = min(res, m);
      r = m - 1;
    } else {
      l = m + 1;
    }
  }

  cout << res;
}
