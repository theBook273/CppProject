#include <bits/stdc++.h>

using namespace std;

const int MAXN = 60;

vector<int> a;
vector<bool> check;
int dem, n, res;

void invite(int x) {
  dem++;
  if (dem == 3) {
    return;
  }
  check[x] = 1;
  if (!check[a[x]]) {
    invite(a[x]);
  }
}

void solve() {
  cin >> n;

  res = 1e9;
  a.resize(n + 1);
  check.assign(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    check.assign(n + 1, 0);
    dem = 0;
    invite(i);
    res = min(res, dem);
  }

  cout << res << "\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
