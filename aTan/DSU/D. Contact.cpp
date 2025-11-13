#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

vector<int> dsu;
int n, m;

int parent(int x) { return (dsu[x] == x ? x : dsu[x] = parent(dsu[x])); }

void join(int x, int y) {
  x = parent(x);
  y = parent(y);
  if (x != y) {
    dsu[x] = y;
  }
}

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

int binPow(int a, int b) {
  int res = 1;

  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }

  return res;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m;

  dsu.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    dsu[i] = i;
  }

  int p1, p2, l;
  while (m--) {
    cin >> p1 >> p2 >> l;
    for (int dem = 0; dem < l; dem++) {
      join(p1 + dem, p2 + dem);
    }
  }

  int dem = 0;
  for (int i = 1; i <= n; i++) {
    if (dsu[i] == i) {
      dem++;
    }
  }

  cout << binPow(2, dem);
}
