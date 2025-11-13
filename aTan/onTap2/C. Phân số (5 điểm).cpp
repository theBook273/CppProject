#include <bits/stdc++.h>
#include <cstdio>
#define int unsigned long long

using namespace std;

struct frac {
  int tu, mau;
};

signed main() {
  cin.tie()->sync_with_stdio(0);

  freopen("PHANSO.INP", "r", stdin);
  freopen("PHANSO.OUT", "w", stdout);

  int n;
  cin >> n;
  vector<frac> phanSo(n);

  for (int i = 0; i < n; i++) {
    cin >> phanSo[i].tu >> phanSo[i].mau;
  }

  int mauChung = phanSo[1].mau;
  for (int i = 0; i < n; i++) {
    mauChung = lcm(mauChung, phanSo[i].mau);
  }

  frac res = {0, mauChung};

  for (int i = 0; i < n; i++) {
    res.tu += phanSo[i].tu * (mauChung / phanSo[i].mau);
  }

  if (res.tu > res.mau) {
    int du = res.tu % res.mau;
    cout << res.tu / res.mau << " ";
    if (du == 0) {
      return 0;
    } else {
      cout << du << " " << res.mau;
    }
  } else {
    cout << res.tu << " " << res.mau;
  }
}
