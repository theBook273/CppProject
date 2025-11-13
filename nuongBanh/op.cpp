#include <bits/stdc++.h>
#include <cstdio>
#define int long long

using namespace std;

const int maxn = 5 * 1e4 + 27;
const int inf = 1e18;

struct matrix {
  int mat[2][2];
  matrix() { mat[0][0] = mat[0][1] = mat[1][0] = mat[1][1] = -inf; }
  matrix(int data) {
    mat[0][0] = mat[0][1] = 0;
    mat[1][0] = data;
    mat[1][1] = -inf;
  }
};

matrix mul(matrix a, matrix b) {
  matrix c;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (a.mat[i][k] != -inf && b.mat[k][j] != -inf) {
          c.mat[i][j] = max(c.mat[i][j], a.mat[i][k] + b.mat[k][j]);
        }
      }
    }
  }
  return c;
}

vector<matrix> st;
int n, d;
vector<int> a;

void build(int id, int l, int r) {
  if (l == r) {
    st[id] = matrix(a[l]);
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  st[id] = mul(st[id * 2 + 1], st[id * 2]);
}

void update(int id, int l, int r, int tar, int data) {
  if (l == r) {
    st[id] = matrix(data);
    return;
  }
  int m = (l + r) / 2;
  if (tar <= m) {
    update(id * 2, l, m, tar, data);
  } else {
    update(id * 2 + 1, m + 1, r, tar, data);
  }
  st[id] = mul(st[id * 2 + 1], st[id * 2]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  freopen("MOONCAKE.INP", "r", stdin);
  freopen("MOONCAKE.OUT", "w", stdout);
  cin >> n >> d;
  st.resize(n * 4 + 4);
  a.resize(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  build(1, 1, n);
  int x, y;
  int tong = 0;
  while (d--) {
    cin >> x >> y;
    update(1, 1, n, x, y);
    tong += max({st[1].mat[0][0], st[1].mat[1][0], 0LL});
  }
  cout << tong;
}
