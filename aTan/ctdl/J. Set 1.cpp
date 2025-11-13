#include <bits/stdc++.h>

using namespace std;

signed main() {
  cin.tie()->sync_with_stdio(0);
  unordered_map<int, int> se;
  int n;
  cin >> n;
  char type;
  int x;
  while (n--) {
    cin >> type >> x;
    if (type == '+') {
      se[x]++;
    } else if (type == '-') {
      se[x] = max(0, se[x] - 1);
    } else {
      cout << (se[x] ? "YES\n" : "NO\n");
    }
  }
}
