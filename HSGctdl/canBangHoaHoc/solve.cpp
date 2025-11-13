#include <bits/stdc++.h>
#define int long long

using namespace std;

unordered_map<char, int> mp;
string s;

void cnt(string phrase, int checkAfter) {
  int mul = 1, idx = 0;
  int i = 0;
  string num;
  char sub;
  if (isdigit(phrase[0])) {
    for (; i < phrase.size() && isdigit(phrase[i]); i++) {
      num.push_back(phrase[i]);
    }
    mul = (num.empty() ? 1 : stoll(num));
  }

  for (; i < phrase.size(); i++) {
    num.clear();

    if (isalpha(phrase[i])) {
      sub = phrase[i];
    }

    if (isdigit(phrase[i + 1])) {
      i++;
      while (isdigit(phrase[i]) && i < phrase.size()) {
        num.push_back(phrase[i]);
        i++;
      }
      i--;
    }

    idx = mul * checkAfter * (num.empty() ? 1 : stoll(num));
    mp[sub] += idx;
  }
}

void solve() {
  mp.clear();
  int after = 1;
  int tong = 0;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    string temp;
    while (s[i] != '+' && s[i] != '-' && s[i] != '>' && i + 1 <= s.size()) {
      temp.push_back(s[i]);
      i++;
    }
    if (s[i] == '>') {
      after = -1;
    }
    cnt(temp, after);
  }

  for (auto [i, j] : mp) {
    if (j != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
