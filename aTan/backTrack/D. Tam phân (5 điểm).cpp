#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

vector<int> s;
int n;
int tong = 0;

void solve() {
  if (s.size() == n) {
    tong = (tong + 1) % MOD;
    return;
  }

  for (int i = 1; i <= 3; i++) {
    if (!s.empty() && s.back() == 1 && i == 1)
      continue;
    s.push_back(i);
    solve();
    s.pop_back();
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  solve();
  cout << tong;
}
