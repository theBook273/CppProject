#include <bits/stdc++.h>
#define int long long

using namespace std;
bool check(int n) {
  int a = round(cbrt((long double)n));
  return (a * a * a == n);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  int n;
  cin >> n;
  for (int temp, i = 0; i < n; i++) {
    cin >> temp;
    cout << (check(temp) ? "YES\n" : "NO\n");
  }
}
