#include <bits/stdc++.h>

using namespace std;

int st[4000009][3];
//[0] left open
//[1] right close
//[2] matched
string s;

void merge(int left[3], int right[3], int curr[3]) {
  int temp = min(left[0], right[1]);
  curr[2] = (temp + right[2] + left[2]);
  curr[0] = ((left[0] - temp) + right[0]);
  curr[1] = ((right[1] - temp) + left[1]);
}

void build(int id, int l, int r) {
  if (l == r) {
    st[id][0] = st[id][1] = st[id][2] = 0;
    st[id][(s[l] == ')')] = 1;
    return;
  }
  int m = (l + r) / 2;
  build(id * 2, l, m);
  build(id * 2 + 1, m + 1, r);
  merge(st[id * 2], st[id * 2 + 1], st[id]);
}

void query(int id, int l, int r, int u, int v, int res[]) {
  if (l > r || l > v || u > r) {
    res[0] = res[1] = res[2] = 0;
    return;
  }
  if (u <= l && r <= v) {
    res[0] = st[id][0];
    res[1] = st[id][1];
    res[2] = st[id][2];
    return;
  }
  int m = (l + r) / 2;
  int left[3] = {0, 0, 0};
  int right[3] = {0, 0, 0};
  query(id * 2, l, m, u, v, left);
  query(id * 2 + 1, m + 1, r, u, v, right);
  merge(left, right, res);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  int n = s.size();
  build(1, 0, n - 1);
  int q;
  cin >> q;
  int res[3];
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    query(1, 0, n - 1, x, y, res);
    cout << res[2] * 2 << "\n";
  }
}
