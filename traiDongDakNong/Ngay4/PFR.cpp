#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<bool> vis;
int n;

int dem(int x) {
  int cnt = 1;

  vis[x] = 1;
  x = a[x];
  while (!vis[x]) {
    vis[x] = 1;
    x = a[x];
    cnt++;
  }

  return cnt;
}

signed main() {
  cin.tie()->sync_with_stdio(0);
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    vis.assign(n + 1, 0);
    cout << dem(i) << "\n";
  }
}
