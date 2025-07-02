#include <bits/stdc++.h>

using namespace std;

long long st[1000][100000][2];
long long n, m;

long long main() {
    cin >> n;

    long long a[n];
    float b[n];

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        st[0][i][0] = st[0][i][1] = a[i];
    }

    for (long long i = 1; pow(2, i - 1) < n; i++) {
        for (long long j = 0; j + pow(2, i - 1) < n; j++) {
            st[i][j][0] =
                min(st[i - 1][j][0], st[i - 1][j + (long long)pow(2, i - 1)][0]);
            st[i][j][1] =
                max(st[i - 1][j][1], st[i - 1][j + (long long)pow(2, i - 1)][1]);
        }
    }

    // for (long long i = 1; pow(2, i - 1) < n; i++) {
    //     for (long long j = 0; j + pow(2, i - 1) < n; j++) {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cin >> m;

    while (m--) {
        long long l, r;
        cin >> l >> r;

        long long log2 = __lg(r - l + 1);

        long long minInBurn =
            min(st[log2][l][0], st[log2][r - (long long)pow(2, log2) + 1][0]);

        long long maxInBurn =
            max(st[log2][l][1], st[log2][r - (long long)pow(2, log2) + 1][1]);

        double maxOutL = 0, maxOutR = 0;

        if (l > 0) {
            long long toL = __lg(l);

            maxOutL = max(st[toL][0][1], st[toL][l - (long long)pow(2, toL)][1]);
        }

        if (r < n - 1) {
            long long toR = __lg(n - 1 - (r + 1) + 1);

            maxOutR = max(st[toR][r + 1][1], st[toR][n - (long long)pow(2, toR)][1]);
        }

        cout << fixed << setprecision(1)
             << max(max(maxOutL, maxOutR), (maxInBurn - minInBurn) / 2.0) +
                    minInBurn
             << endl;

        // cout << minInBurn << " " << maxInBurn << endl;
        // cout << maxOutL << " " << maxOutR << endl;
    }
}
