#include <bits/stdc++.h>
#define int long long

using namespace std;

bool solve(int a, int b, int c) { return (c == a + b); }

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  vector<int> num(3);
  while (t--) {
    cin >> num[0] >> num[1] >> num[2];
    sort(num.begin(), num.end());
    if (solve(num[0], num[1], num[2])) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
