#include <bits/stdc++.h>

using namespace std;

vector<int> s;
int n;

void solve() {
  if (s.size() == n) {
    for (auto i : s) {
      cout << i;
    }
    cout << "\n";
    return;
  }
  for (int i = 0; i <= 1; i++) {
    s.push_back(i);
    solve();
    s.pop_back();
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  solve();
}
