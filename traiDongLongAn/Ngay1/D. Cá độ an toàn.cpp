#include <bits/stdc++.h>
#define double long double

using namespace std;

vector<double> X, Y, preX, preY;
int n;

bool check(double x) {
  for (int i = 0; i <= n; i++) {
    int maxL = floor(preX[i] - x);

    if (maxL < 0) {
      continue;
    }
    if (maxL > n) {
      maxL = n;
    }

    double need = i + x;
    int l =
        lower_bound(preY.begin(), preY.begin() + maxL + 1, need) - preY.begin();

    if (l <= maxL) {
      return 1;
    }
  }
  return 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("sure.inp", "r", stdin);
  freopen("sure.out", "w", stdout);

  cin >> n;

  X.resize(n + 1, 0);
  Y.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    cin >> X[i] >> Y[i];
    X[i] -= 1.0;
    Y[i] -= 1.0;
  }

  sort(X.begin() + 1, X.begin() + n + 1, greater<>());
  sort(Y.begin() + 1, Y.begin() + n + 1, greater<>());

  preX.resize(n + 1, 0);
  preY.resize(n + 1, 0);

  for (int i = 1; i <= n; i++) {
    preX[i] = preX[i - 1] + X[i];
    preY[i] = preY[i - 1] + Y[i];
  }

  double l = -1e18, r = 1e18;
  for (int i = 0; i < 100; i++) {
    double mid((l + r) / 2);
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << fixed << setprecision(4) << l;
}
