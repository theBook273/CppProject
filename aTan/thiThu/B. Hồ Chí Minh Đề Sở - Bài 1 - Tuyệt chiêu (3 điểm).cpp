#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, k, res = 1e18;
  cin >> n >> k;
  vector<int> a(n + 1);
  unordered_map<int, int> last;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (last.count(a[i]) && i - last[a[i]] < k) {
      res = min(res, a[i]);
    }
    last[a[i]] = i;
  }
  cout << (res == 1e18 ? -1 : res);
}
