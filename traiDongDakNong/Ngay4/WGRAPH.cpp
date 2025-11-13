#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int n, m, k, tong = 0;
map<pair<int, int>, int> board;

int mul(int a, int b) { return ((a % MOD) * (b % MOD)) % MOD; }
int add(int a, int b) { return ((a % MOD) + (b % MOD)) % MOD; }

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

vector<int> se;
void gen(int sz) {
  if ((int)se.size() == sz) {
    // for (auto &i : se) {
    //   cout << i << " ";
    // }

    int temp = 0;
    for (int i = 0; i < sz; i++) {
      for (int j = 0; j < i; j++) {
        temp = add(temp, board[{se[j], se[i]}]);
      }
    }
    // cout << ": " << temp << "\n";

    tong = add(tong, binPow(temp, k));
    return;
  }
  int now = (se.empty() ? 0 : se.back());
  for (int i = now + 1; i <= n; i++) {
    se.push_back(i);
    gen(sz);
    se.pop_back();
  }
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int u, v, i = 0; i < m; i++) {
    cin >> u >> v;
    if (u > v) {
      swap(u, v);
    }
    board[{u, v}]++;
  }

  // for (auto [i, j] : board) {
  //   cout << i.first << " " << i.second << " " << j << "\n";
  // }

  tong = add(m, binPow(m, k));
  for (int i = 3; i < n; i++) {
    gen(i);
  }

  cout << tong % MOD;
}
