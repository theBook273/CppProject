#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 20020303;

void add(int &a, int &b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<int> f(n + 1, 0);
  f[0] = 1;

  for (int i = 1; i <= n; i++) {
    add(f[i], f[i - 1]);
    int x = i - k - 1;
    if (x >= 0) {
      add(f[i], f[x]);
    }
  }

  cout << f[n];
}
