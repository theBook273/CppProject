#include <bits/stdc++.h>
#define int long long

using namespace std;

vector<float> dis;
int n, x, y, a, b;

float euclid() {
  int temp1 = (x - a) * (x - a);
  int temp2 = (y - b) * (y - b);
  return (sqrt(temp1 + temp2));
}

void solve() {
  cin >> n >> x >> y >> a >> b;
  dis.resize(n);

  for (auto &i : dis) {
    cin >> i;
  }

  dis.push_back(euclid());
  sort(dis.begin(), dis.end());

  float tong = dis.back();
  for (int i = 0; i < dis.size() - 1; i++) {
    tong -= dis[i];
  }

  cout << ((tong <= 0) ? "Yes\n" : "No\n");
}

signed main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
