#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<long long> a(n);
  for (auto &x : a)
    cin >> x;

  long long sum = 0;
  long long mx = 0;
  for (auto &x : a) {
    sum += x;
    mx = max(mx, x);
  }

  cout << max(sum, 2 * mx);
}
