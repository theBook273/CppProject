#include <bits/stdc++.h>

using namespace std;

vector<int> s;
int tong[2] = {0, 0};
int n;

void solve() {
  if (s.size() == n) {
    if (tong[0] == tong[1]) {
      for (auto i : s) {
        cout << i;
      }
      cout << "\n";
    }
    return;
  }

  for (int i = 0; i <= 1; i++) {
    s.push_back(i);
    tong[s.size() % 2] += i;
    solve();
    tong[s.size() % 2] -= i;
    s.pop_back();
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  solve();
}
