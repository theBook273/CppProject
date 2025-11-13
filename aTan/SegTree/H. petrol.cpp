#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<pair<int, int>> a;
vector<int> st, maxL, maxR;
int n, d, ans;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = a[l].second;
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return 0;
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m = (l + r) / 2;
  int left = query(l, m, u, v, id * 2);
  int right = query(m + 1, r, u, v, id * 2 + 1);
  return max(left, right);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> d;
  a.resize(n);
  maxL.resize(n);
  maxR.resize(n);
  st.resize(n * 4 + 5);
  for (auto &[i, j] : a) {
    cin >> i >> j;
  }
  sort(a.begin(), a.end());
  build(0, n - 1, 1);

  for (int l = 0, i = 0; i < n; i++) {
    while (a[i].first - a[l].first > d) {
      l++;
    }
    if (l < i) {
      maxL[i] = query(0, n - 1, l, i - 1, 1);
    }
  }

  for (int r = n - 1, i = n - 1; i >= 0; i--) {
    while (a[r].first - a[i].first > d) {
      r--;
    }
    if (r > i) {
      maxR[i] = query(0, n - 1, i + 1, r, 1);
    }
  }

  ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (maxL[i] >= a[i].second * 2 && maxR[i] >= a[i].second * 2);
  }
  cout << ans;
}
