#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;

  unordered_map<int, int> cnt;
  cnt[0] = 1;

  long long pre = 0, ans = 0;
  for (int x : a) {
    pre = (pre + x) % k;
    if (pre < 0)
      pre += k;
    ans += cnt[pre];
    cnt[pre]++;
  }

  cout << ans;
}
