#include <bits/stdc++.h>

using namespace std;

long long a[1000][1000], res[1000][1000], n, m, maxRes = 0;

void dp() {
    for (long long i = n - 1; i >= 0; i--) {
        if (a[i][m - 1] == 1) {
            res[i][m - 1] = 1;
        }
    }
    for (long long i = m - 1; i >= 0; i--) {
        if (a[n - 1][i] == 1) {
            res[n - 1][i] = 1;
        }
    }
    for (long long i = n - 2; i >= 0; i--) {
        for (long long j = m - 2; j >= 0; j--) {
            if (a[i][j] == 1) {
                res[i][j] =
                    min(res[i + 1][j], min(res[i + 1][j + 1], res[i][j + 1])) +
                    1;
                maxRes = max(maxRes, res[i][j]);
            } else {
                res[i][j] = 0;
            }
        }
    }
}

signed main() {
    cin >> n >> m;

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    dp();

    cout << maxRes << endl;
}