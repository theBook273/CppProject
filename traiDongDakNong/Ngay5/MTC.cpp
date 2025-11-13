#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 1e9 + 7;

vector<int> a, inc, de, stIn, stDe, val;
int n, m, ans = 0;

int add(int a, int b) { return (a % MOD + b % MOD) % MOD; }
int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }

void compress() {
  val = a;
  sort(val.begin(), val.end());
  val.erase(unique(val.begin(), val.end()), val.end());
  for (auto &i : a) {
    i = lower_bound(val.begin(), val.end(), i) - val.begin() + 1;
  }
  m = val.size();
}

void update(vector<int> &st, int l, int r, int tar, int x, int id) {
  if (l == r) {
    st[id] = add(st[id], x);
    return;
  }
  int mid((l + r) / 2);
  if (tar <= mid) {
    update(st, l, mid, tar, x, id << 1);
  } else {
    update(st, mid + 1, r, tar, x, id << 1 | 1);
  }
  st[id] = add(st[id << 1], st[id << 1 | 1]);
}

int query(vector<int> &st, int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int mid((l + r) / 2);
  return add(query(st, l, mid, u, v, id << 1),
             query(st, mid + 1, r, u, v, id << 1 | 1));
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  a.resize(n), inc.resize(n), de.resize(n);
  for (auto &i : a) {
    cin >> i;
  }

  compress();
  stIn.resize(4 * m + 5, 0);
  stDe.resize(4 * m + 5, 0);

  for (int i = 0; i < n; i++) {
    int s = query(stIn, 1, m, 1, a[i] - 1, 1);
    inc[i] = (s + 1) % MOD;
    update(stIn, 1, m, a[i], inc[i], 1);
  }

  for (int i = n - 1; i >= 0; i--) {
    int s = query(stDe, 1, m, 1, a[i] - 1, 1);
    de[i] = (s + 1) % MOD;
    update(stDe, 1, m, a[i], de[i], 1);
  }

  for (int i = 0; i < n; i++) {
    ans = add(ans, mul(inc[i], de[i]));
  }

  cout << add(ans, 1);
}
