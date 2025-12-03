#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, res = 0;
  string s;
  cin >> n >> s;

  vector<string> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  for (auto &x : a) {
    string temp = x.substr(0, s.size());
    if (temp == s) {
      res++;
    }
  }

  cout << res;
}
