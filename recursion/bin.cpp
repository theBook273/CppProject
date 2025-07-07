#include <bits/stdc++.h>

using namespace std;
int n, k;
string s = "";

void bin(int dem) {
  if (s.size() == k) {
    cout << s << " ";
    return;
  }
  for (int i = dem; i <= n; i++) {
    s += to_string(i);
    bin(i + 1);
    s.pop_back();
  }
}

signed main() {
  cin >> n >> k;
  bin(1);
}
