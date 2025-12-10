#include <bits/stdc++.h>
#define int long long

using namespace std;

string a;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> a;

  int neo = a.size();

  for (int i = 0; i < (int)a.size(); i++) {
    if (a[i] != '9') {
      neo = i;
      break;
    }
  }

  if (neo < (int)a.size()) {
    int temp = 0;
    for (int i = neo + 1; i < (int)a.size(); i++) {
      temp += a[i] - '0';
    }
    if (temp == 0 && neo + 1 != (int)a.size()) {
      a[a.size() - 1] = '1';
    } else {
      a[neo]++;
      for (int i = neo + 1; i < (int)a.size(); i++) {
        a[i] = '0';
      }
    }

  } else {
    string temp = "1";
    while (temp.size() <= a.size()) {
      temp.push_back('0');
    }
    a = temp;
  }

  if (a[a.size() - 1] == '0') {
    a[a.size() - 1] = '1';
  }

  reverse(a.begin(), a.end());

  cout << a;
}
