#include <bits/stdc++.h>

using namespace std;

vector<int> de;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  freopen("test.inp", "r", stdin);
  freopen("chuan.out", "w", stdout);

  int n;
  cin >> n;
  for (int i = 0, temp; i < n; i++) {
    cin >> temp;
    de.push_back(temp);
  }
  bool able = 1;
  do {
    able = 0;
    for (int i = 0; i < (int)de.size() - 1; ++i) {
      if ((de[i] + de[i + 1]) % 2 == 0) {
        de.erase(de.begin() + i);
        de.erase(de.begin() + i);
        able = 1;
      }
    }
  } while (able);

  cout << de.size();
}
