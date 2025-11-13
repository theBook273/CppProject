#include <bits/stdc++.h>

using namespace std;

int res;
bool flag(1);

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> sub(n + 1);
  vector<int> rep[n + 1];
  vector<int> toUse(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> sub[i];
  }

  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int des, l;
    cin >> des >> l;
    int temp;
    while (l--) {
      cin >> temp;
      rep[des].push_back(temp);
    }
  }

  while (flag) {
    for (int need : rep[n]) {
      toUse[need]++;
    }

    for (int i = n - 1; i >= 1; i--) {
      if (toUse[i]) {
        int satis = min(toUse[i], sub[i]);
        sub[i] -= satis;
        toUse[i] -= satis;
        if (toUse[i]) {
          if (rep[i].empty()) {
            flag = 0;
            break;
          }

          for (int need : rep[i]) {
            toUse[need] += toUse[i];
          }
          toUse[i] = 0;
        }
      }
    }

    for (auto check : toUse) {
      if (check) {
        flag = 0;
        break;
      }
    }

    if (!flag)
      break;
    res++;
  }

  cout << res + sub[n] << "\n";
}
