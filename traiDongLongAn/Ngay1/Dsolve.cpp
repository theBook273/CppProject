#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<double> x(n), y(n);
  for (int i = 0; i < n; i++) {
    double t, r;
    cin >> t >> r;
    x[i] = t - 1.0;
    y[i] = r - 1.0;
  }

  sort(x.begin(), x.end(), greater<double>());
  sort(y.begin(), y.end(), greater<double>());

  vector<double> prefX(n + 1, 0), prefY(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    prefX[i] = prefX[i - 1] + x[i - 1];
    prefY[i] = prefY[i - 1] + y[i - 1];
  }

  auto check = [&](double K) {
    // duyệt k = số lượng chọn bên T1
    for (int k = 0; k <= n; k++) {
      // from condition 1': prefX[k] - l >= K  →  l <= prefX[k] - K
      double maxL = prefX[k] - K;
      int lmax = (int)floor(maxL);
      if (lmax < 0)
        continue;
      if (lmax > n)
        lmax = n;

      // need l satisfying: prefY[l] >= K + k
      double need = K + k;

      // binary search l in [0..lmax]
      int l = lower_bound(prefY.begin(), prefY.begin() + lmax + 1, need) -
              prefY.begin();

      if (l <= lmax)
        return true;
    }
    return false;
  };

  // binary search answer K
  double lo = -1e5, hi = 1e5;
  for (int it = 0; it < 60; it++) {
    double mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid;
  }

  cout << fixed << setprecision(4) << lo << "\n";
  return 0;
}
