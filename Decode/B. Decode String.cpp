#include <bits/stdc++.h>

using namespace std;

void solve();
void toC();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}

char toC(int x) { return char(x + 'a' - 1); }

void solve() {
  int n;
  cin >> n;
  vector<char> s(n);
  for (auto &i : s) {
    cin >> i;
  }

  string res;

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      i--;
      int tong = s[i] - '0';
      i--;
      tong = (s[i] - '0') * 10 + tong;
      res.push_back(toC(tong));
    } else {
      res.push_back(toC(s[i] - '0'));
    }
  }

  for (int i = res.size() - 1; i >= 0; i--) {
    cout << res[i];
  }
  cout << "\n";
}
