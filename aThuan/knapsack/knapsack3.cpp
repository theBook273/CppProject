#include <bits/stdc++.h>
#include <vector>
#define int long long

using namespace std;

const int N = 20;

int n, w, ww[N], vv[N], vs = 0, cnt = 0, smask;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> w;
  for (int i = 0; i < n; i++) {
    cin >> ww[i] >> vv[i];
  }

  int full = (1 << n);
  for (int mask = 0; mask < full; mask++) {
    vector<int> pos;
    for (int i = 0; i < n; i++) {
      if ((mask >> i) & 1) {
        pos.push_back(i);
      }
    }

    int vt = 0, wt = 0, dem = 0;
    for (int i : pos) {
      vt += vv[i];
      wt += ww[i];
      dem++;
    }

    if (vt > vs && wt <= w) {
      cnt = dem;
      vs = vt;
      smask = mask;
    }
  }

  cout << cnt << "\n";
  for (int i = 0; i < n; i++) {
    if ((smask >> i) & 1) {
      cout << i + 1 << " ";
    }
  }
}
