#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

vector<pair<int, int>> fact(int n) {
  vector<pair<int, int>> prime;
  for (int i = 2; i * i <= n; i++) {
    int mu = 0;
    while (n % i == 0) {
      n /= i;
      mu++;
    }
    if (mu != 0) {
      prime.push_back({i, mu});
    }
  }
  if (n > 1) {
    prime.push_back({n, 1});
  }
  return prime;
}

void solve() {
  int a, b;
  cin >> a >> b;

  vector<pair<int, int>> priA = fact(a);
  vector<pair<int, int>> priB = fact(b);
  map<int, int> mp;
  vector<int> prime;

  for (auto &[x, mu] : priA) {
    mp[x] += mu;
  }

  for (auto &[x, mu] : priB) {
    mp[x] += mu;
  }

  for (auto &[x, mu] : mp) {
    if (mu % 2 != 0) {
      prime.push_back(x);
    }
  }

  sort(prime.begin(), prime.end());
  prime.erase(unique(prime.begin(), prime.end()), prime.end());

  vector<int> res(3);
  res[0] = a + b;
  res[1] = a;
  res[2] = b;

  int full = (1 << prime.size());
  for (int mask = 0; mask < full; mask++) {
    int x = 1, y = 1;
    for (int i = 0; i < (int)prime.size(); i++) {
      if ((mask >> i) & 1) {
        y *= prime[i];
      } else {
        x *= prime[i];
      }
    }
    if (res[0] > x + y) {
      res[0] = x + y;
      res[1] = x;
      res[2] = y;
    }
  }

  cout << res[1] << " " << res[2] << endl;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("minsum.inp", "r", stdin);
  freopen("minsum.out", "w", stdout);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
