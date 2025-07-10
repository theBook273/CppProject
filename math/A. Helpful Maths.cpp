#include <bits/stdc++.h>
#include <cctype>

using namespace std;

signed main() {
  string s;
  cin >> s;
  vector<int> a;
  for (auto i : s) {
    if (isalnum(i)) {
      a.push_back(i - '0');
    }
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] << ((i + 1 != a.size()) ? "+" : "\n");
  }
}
