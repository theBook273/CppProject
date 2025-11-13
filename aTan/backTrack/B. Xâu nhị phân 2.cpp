#include <bits/stdc++.h>

using namespace std;

vector<int> s = {1};
int n, k, dem = 1;

void solve() {
  if (s.size() == n && dem <= k) {
    for (auto i : s) {
      cout << i;
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i <= 1; i++) {
    s.push_back(i);
    dem += i;
    if (dem <= k)
      solve();
    s.pop_back();
    dem -= i;
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> k;
  solve();
}
