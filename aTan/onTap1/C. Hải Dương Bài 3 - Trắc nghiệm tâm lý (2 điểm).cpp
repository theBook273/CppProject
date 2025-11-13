#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 5;
int pre[MAXN], a[MAXN];

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n, q, l, r;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l;
    a[l]++;
  }

  pre[0] = a[0];
  for (int i = 1; i <= MAXN; i++) {
    pre[i] = pre[i - 1] + a[i];
  }

  cin >> q;
  while (q--) {
    cin >> l >> r;
    cout << pre[r] - pre[l - 1] << "\n";
  }
}
