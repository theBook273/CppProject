#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
  int n;
  string ene, aly;
  cin >> n >> ene >> aly;
  int res = 0;

  for (int i = 0; i < n; i++) {
    if (aly[i] == '1' && ene[i] == '0') {
      res++;
      aly[i] = '0';
      ene[i] = 'e';
    } else if (aly[i] == '1' && (ene[i] == '1' || ene[i] == 'e')) {
      if (i - 1 >= 0 && ene[i - 1] == '1') {
        res++;
        aly[i] = '0';
      } else if (i + 1 <= n && ene[i + 1] == '1') {
        res++;
        aly[i] = '0';
        ene[i + 1] = 'e';
      }
    }
  }

  // cout << ene << "\n" << aly << "\n \n";
  cout << res << "\n";
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
