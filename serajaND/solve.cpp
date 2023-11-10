#include <bits/stdc++.h>

using namespace std;
int n, m, t, d, a[100006], st[26][100006];

int findMax(int l, int r) {
    int k = __lg(r - l + 1);

    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    a[n] = INT_MAX;

    for (int i = 0; i < n; i++) {
        st[0][i] = a[i + 1] - a[i];
    }

    for (int i = 1; i <= __lg(n + 1); i++) {
        for (int j = 0; j + (1 << i) - 1 <= n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    cin >> m;

    while (m--) {
        cin >> t >> d;

        int pos = upper_bound(a, a + n, t) - a - 1;

        int res = pos + 1, r = pos - 1, l = 0, m;

        if (pos == 0) {
            cout << 1 << endl;
            continue;
        }

        while (l <= r) {
            m = (l + r) >> 1;

            if (findMax(m, r) <= d)
                res = m + 1, r = m - 1;
            else
                l = m + 1;
        }

        cout << res << endl;
    }
}