#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

const string ans[] = {"No\n", "Yes\n"};

bool able(string a, string b) {
  // cout << a << " " << b << "\n";
  if (a == b) {
    return 1;
  }

  bool isAble = 0;

  if (b[0] == 'B') {
    string temp = b.substr(1);
    reverse(temp.begin(), temp.end());
    isAble = (isAble || able(a, temp));
  }

  if (b.back() == 'A') {
    string temp = b;
    temp.pop_back();
    isAble = (isAble || able(a, temp));
  }

  return isAble;
}

void solve() {
  string a, b;
  cin >> a >> b;
  cout << ans[able(a, b)];
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  freopen("abba.inp", "r", stdin);
  freopen("abba.out", "w", stdout);
  for (int i = 0; i < 3; i++) {
    solve();
  }
}
