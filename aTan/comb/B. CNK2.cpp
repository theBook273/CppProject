#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MOD = 28082002;
const int N = 5000;

int C[N + 5][N + 5];

void init() {
  for (int i = 0; i <= N; i++) {
    C[i][0] = 1;
    C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  init();

  int n, a, b;
  cin >> n;

  while (n--) {
    cin >> a >> b;
    cout << C[a][b] << "\n";
  }
}
