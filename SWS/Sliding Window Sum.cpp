#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k, x, a, b, c;
  cin >> n >> k >> x >> a >> b >> c;
  vector<int> arr;
  arr.push_back(x);
  for (int i = 1; i < n; ++i) {
    arr.push_back((a * arr.back() + b) % c);
  }
  vector<int> tong;
  int temp = 0;
  for (int l = 0, r = 0; r < n; ++r) {
    temp += arr[r];
    if (r - l + 1 == k) {
      tong.push_back(temp);
      temp -= arr[l];
      l++;
    }
  }
  int res = 0;
  for (auto i : tong) {
    res ^= i;
  }
  cout << res;
}
