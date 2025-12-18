#include <bits/stdc++.h>
#include <cstdio>
#define int unsigned long long

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("CHC.INP", "r", stdin);
  freopen("CHC.OUT", "w", stdout);

  string s;
  cin >> s;
  map<char, int> M;
  M['C'] = 12;
  M['H'] = 1;
  M['O'] = 16;
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    if (M.count(s[i])) {
      int chuan = i;
      string temp;
      i++;
      while (isdigit(s[i])) {
        temp.push_back(s[i]);
        i++;
      }
      if (temp.empty())
        temp = "1";
      res += (M[s[chuan]] * stoull(temp));
      i--;
    }
  }
  cout << res;
}
