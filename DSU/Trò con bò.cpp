#include <bits/stdc++.h>

using namespace std;

int n, m;

namespace sub1 {
vector<int> dsu, tong;
string type;
int v, x;

int find(int p) {
  if (dsu[p] == p) {
    return p;
  }
  return dsu[p] = find(dsu[p]);
}

void join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a != b) {
    dsu[a] = b;
  }
}

void solve() {
  for (int i = 0; i <= n; i++) {
    dsu.push_back(i);
    tong.push_back(0);
  }

  while (m--) {
    cin >> type;
    if (type == "join") {
      cin >> x >> v;
      join(x, v);
    } else if (type == "add") {
      cin >> x >> v;
      x = find(x);
      for (int i = 1; i <= n; i++) {
        if (find(i) == x) {
          tong[i] += v;
        }
      }
    } else {
      cin >> x;
      cout << tong[x] << "\n";
    }
  }
}

} // namespace sub1

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  sub1::solve();
}
