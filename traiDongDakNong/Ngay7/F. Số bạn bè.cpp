#include <bits/stdc++.h>
#include <cstdio>
#include <vector>

using namespace std;

bool isFriend(string a, string b) {
  set<char> seA, seB;
  for (auto &i : a) {
    seA.insert(i);
  }

  for (auto &i : b) {
    seB.insert(i);
  }

  return seA == seB;
}

vector<string> gen(string a) {
  vector<string> x;
  for (int i = 0; i < a.size() - 1; i++) {
    string s = a;
    if (!(s[i] == '1' && i == 0) && s[i] > '0' && s[i + 1] < '9') {
      s[i]--;
      s[i + 1]++;
    }
    x.push_back(s);
    s = a;
    if (s[i] < '9' && s[i + 1] > '0') {
      s[i]++;
      s[i + 1]--;
    }
    x.push_back(s);
  }
  return x;
}

bool almost(string a, string b) {
  vector<string> x = gen(b);
  for (auto i : x) {
    if (isFriend(a, i)) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("digits.inp", "r", stdin);
  freopen("digits.out", "w", stdout);

  string a, b;
  cin >> a >> b;

  if (isFriend(a, b)) {
    cout << "friends";
  } else {
    if (almost(a, b) || almost(b, a)) {
      cout << "almost friends";
    } else {
      cout << "nothing";
    }
  }
}
