#include <bits/stdc++.h>

using namespace std;

char Nu[] = {'A', 'T', 'G', 'X'};
int res = INT_MAX;
vector<int> pos;
string s;

int cnt() {
  int n = s.size();
  int total = n * (n + 1) / 2;
  int same = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && s[j] == s[i])
      j++;
    int len = j - i;
    same += len * (len + 1) / 2;
    i = j;
  }
  return total - same;
}

void gen(int idx) {
  if (idx == (int)pos.size()) {
    // cout << s << "\n";
    res = min(res, cnt());
    return;
  }
  int i = pos[idx];
  for (auto nu : Nu) {
    s[i] = nu;
    gen(idx + 1);
  }
  s[i] = '?';
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> s;
  for (int i = 0; i < int(s.size()); i++) {
    if (s[i] == '?')
      pos.push_back(i);
  }
  gen(0);
  cout << res;
}
