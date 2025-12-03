#include <bits/stdc++.h>

using namespace std;

const int lim = 30;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<string> a(lim + 5);
  a[1] = 'A';
  a[2] = 'B';
  for (int i = 3; i <= lim; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }

  int n;
  string s;
  while (cin >> n >> s) {
    int res = 0;
    string mod = a[n];
    for (int i = 0; i < (int)mod.size(); i++) {
      string temp = mod.substr(i, s.size());
      if (temp == s) {
        res++;
      }
    }

    cout << res << "\n";
  }
}
