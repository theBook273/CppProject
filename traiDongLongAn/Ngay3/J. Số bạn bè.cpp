#include <bits/stdc++.h>
#define int long long

using namespace std;

bool isfriend(string a, string b) {
  set<char> s1, s2;
  for (auto s : a) {
    s1.insert(s);
  }

  for (auto s : b) {
    s2.insert(s);
  }

  return (s1 == s2);
}

string change1(string b, int i) {
  if (i == 0 && b[i] == '1') {
    return b;
  }
  if (b[i] > '0' && b[i + 1] < '9') {
    b[i]--;
    b[i + 1]++;
  }
  return b;
}

string change2(string b, int i) {
  if (b[i] < '9' && b[i + 1] > '0') {
    b[i]++;
    b[i + 1]--;
  }
  return b;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("digits.inp", "r", stdin);
  freopen("digits.out", "w", stdout);

  string a, b;
  cin >> a >> b;

  if (isfriend(a, b)) {
    cout << "friends";
  } else {
    for (int i = 0; i < b.size() - 1; i++) {
      if (isfriend(a, change1(b, i)) || isfriend(a, change2(b, i))) {
        cout << "almost friends";
        return 0;
      }
    }

    swap(a, b);
    for (int i = 0; i < b.size() - 1; i++) {
      if (isfriend(a, change1(b, i)) || isfriend(a, change2(b, i))) {
        cout << "almost friends";
        return 0;
      }
    }

    cout << "nothing";
  }
}
