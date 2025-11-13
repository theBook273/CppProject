#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

int n, q;
bool prime[MAXN], check[MAXN];
vector<int> primeNum;
unordered_map<int, vector<int>> mp;

signed main() {
  cin.tie()->sync_with_stdio(0);

  memset(prime, 1, sizeof(prime));
  prime[0] = prime[1] = 0;
  for (int i = 2; i <= MAXN; i++) {
    if (prime[i]) {
      primeNum.push_back(i);
      for (int j = 2; j * i <= MAXN; j++) {
        prime[i * j] = 0;
      }
    }
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    check[i] = 0;
    for (auto x : primeNum) {
      if (x <= i) {
        if (i % x == 0) {
          mp[x].push_back(i);
        }
      } else {
        break;
      }
    }
  }

  // for (auto [i, j] : mp) {
  //   cout << i << ": ";
  //   for (auto x : j) {
  //     cout << x << " ";
  //   }
  //   cout << "\n";
  // }

  char type;
  int a, b;
  while (q--) {
    cin >> type;
    if (type == 'S') {
      cin >> a;
      check[a] = !check[a];
    } else {
      cin >> a >> b;
      bool flag = 0;
      for (auto [i, j] : mp) {
        int cnt = 0;
        if (flag)
          break;

        for (int k : j) {
          if (a <= k && k <= b && check[k]) {
            cnt++;
            if (cnt == 2) {
              flag = 1;
              break;
            }
          }
        }
      }
      if (flag) {
        cout << "DA\n";
      } else {
        cout << "NE\n";
      }
    }
  }
}
