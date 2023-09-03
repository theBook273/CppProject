#include <bits/stdc++.h>

using namespace std;

int st[1000][100000][2];
int n, m;

int main() {
    cin >> n;

    int a[n];
    float b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[0][i][0] = st[0][i][1] = a[i];
    }

    for (int i = 1; pow(2, i - 1) < n; i++) {
        for (int j = 0; j + pow(2, i - 1) < n; j++) {
            st[i][j][0] =
                min(st[i - 1][j][0], st[i - 1][j + (int)pow(2, i - 1)][0]);
            st[i][j][1] =
                max(st[i - 1][j][1], st[i - 1][j + (int)pow(2, i - 1)][1]);
        }
    }

    // for (int i = 1; pow(2, i - 1) < n; i++) {
    //     for (int j = 0; j + pow(2, i - 1) < n; j++) {
    //         cout << st[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cin >> m;

    while (m--) {
        int l, r;
        cin >> l >> r;

        int log2 = __lg(r - l + 1);

        int minInBurn =
            min(st[log2][l][0], st[log2][r - (int)pow(2, log2) + 1][0]);

        int maxInBurn =
            max(st[log2][l][1], st[log2][r - (int)pow(2, log2) + 1][1]);

        double maxOutL = 0, maxOutR = 0;

        if (l > 0) {
            int toL = __lg(l);

            maxOutL = max(st[toL][0][1], st[toL][l - (int)pow(2, toL)][1]);
        }

        if (r < n - 1) {
            int toR = __lg(n - 1 - (r + 1) + 1);

            maxOutR = max(st[toR][r + 1][1], st[toR][n - (int)pow(2, toR)][1]);
        }

        cout << fixed << setprecision(1)
             << max(max(maxOutL, maxOutR), (maxInBurn - minInBurn) / 2.0) +
                    minInBurn
             << endl;

        // cout << minInBurn << " " << maxInBurn << endl;
        // cout << maxOutL << " " << maxOutR << endl;
    }
}