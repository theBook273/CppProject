#include <bits/stdc++.h>

using namespace std;

struct Query {
  int left, right, id;
};

int n, q, s, cnt = 0;
vector<int> a, res;
vector<Query> query;
unordered_map<int, int> mp;

bool comp(Query a, Query b) {
  if (a.left / s != b.left / s) {
    return a.left < b.left;
  }
  return a.right < b.right;
}

void add(int pos) { mp[a[pos]]++; }

void sub(int pos) { mp[a[pos]]--; }

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> q;
  s = sqrt(n);
  res.resize(q);
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int l, r, i = 0; i < q; i++) {
    cin >> l >> r;
    query.push_back({l, r, i});
  }

  sort(query.begin(), query.end(), comp);

  int l = 0, r = 0;
  for (auto [x, y, id] : query) {
    while (l > x) {
      add(--l);
    }
    while (r < y) {
      add(++r);
    }
    while (l < x) {
      sub(l++);
    }
    while (r > y) {
      sub(r--);
    }
    cnt = 0;
    for (auto [i, j] : mp) {
      if (j == 2) {
        cnt++;
      }
    }
    res[id] = cnt;
  }

  for (auto i : res) {
    cout << i << "\n";
  }
}
