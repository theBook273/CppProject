#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> rep[n + 1];
  vector<int> toUse(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int m;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int num, desti;
    cin >> desti >> num;
    int temp;
    while (num--) {
      cin >> temp;
      rep[desti].push_back(temp);
    }
  }

  int res = 0;
  while (true) {
    fill(toUse.begin(), toUse.end(), 0);
    for (int need : rep[n]) {
      toUse[need]++;
    }

    for (int i = n - 1; i >= 0; i--) {
      if (toUse[i]) {
        int satis = min(toUse[i], a[i]);
        a[i] -= satis;
        toUse[i] -= satis;
        if (toUse[i]) {
          for (auto need : rep[i]) {
            toUse[need]++;
          }
        }
      }
    }

    for (auto i : toUse) {
      if (i)
        break;
    }
    res++;
    cout << res << "\n";
  }

  cout << res;
}
