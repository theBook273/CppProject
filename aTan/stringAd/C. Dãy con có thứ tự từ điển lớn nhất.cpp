#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<char> s(n);

  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  vector<char> res;
  char best = 'a';
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] >= best) {
      res.push_back(s[i]);
      best = s[i];
    }
  }

  reverse(res.begin(), res.end());
  for (auto &i : res) {
    cout << i;
  }
}
