#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e9;

int model;

void solve() {
  int a;
  cin >> a;

  for (int i = 1; i * i <= a + N + 1; i++) {
    int y = i * i - a - 1;
    if (1 <= y && y <= N) {
      cout << 1 << " " << y << "\n";
      return;
    }
  }
  cout << "-1\n";
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i * i <= N; i++) {
    model = i * i;
  }

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
