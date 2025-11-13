#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<int> a;
vector<pair<int, int>> st;
int n;

void build(int l, int r, int id) {
  if (l == r) {
    st[id] = {a[l], l};
    return;
  }
  int m = (l + r) / 2;
  build(l, m, id * 2);
  build(m + 1, r, id * 2 + 1);
  st[id] = min(st[id * 2], st[id * 2 + 1]);
}

pair<int, int> query(int l, int r, int u, int v, int id) {
  if (l > r || l > v || u > r) {
    return {LLONG_MAX, LLONG_MAX};
  }
  if (u <= l && r <= v) {
    return st[id];
  }
  int m = (l + r) / 2;
  return min(query(l, m, u, v, id * 2), query(m + 1, r, u, v, id * 2 + 1));
}

int dnc(int l, int r, int sub) {
  if (l > r) {
    return 0;
  }

  pair<int, int> minQ = query(1, n, l, r, 1);
  int mini = minQ.first;
  int mid = minQ.second;

  return dnc(l, mid - 1, mini) + dnc(mid + 1, r, mini) + (mini != sub);
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  a.resize(n + 1);
  st.resize(n * 4 + 5);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  build(1, n, 1);
  cout << dnc(1, n, 0);
}
