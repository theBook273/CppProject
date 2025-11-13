#include <bits/stdc++.h>
#include <cctype>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n, res = 0;
  string s;
  cin >> s;
  n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      i++;
      string temp;
      for (; i < n && isdigit(s[i]); i++) {
        temp.push_back(s[i]);
      }
      if (!temp.empty())
        res = max(res, stoull(temp));
      i--;
    }
  }
  cout << res;
}
