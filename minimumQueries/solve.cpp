#include <bits/stdc++.h>

using namespace std;
long long n, m;
long long a[50004], st[100][50004];

long long main() {
    cin >> n >> m;

    long long tong = m;

    for (long long i = 1; i <= n; i++) cin >> a[i], st[0][i] = a[i];

    for (long long i = 1; (1 << i) <= n; i++)
        for (long long j = 1; j + (1 << i) - 1 <= n; j++)
            st[i][j] = max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);

    for (long long i = 0; i < m; i++) {
        long long r, l;

        cin >> l >> r;
        if (abs(l - r) <= 1) {
            continue;
        }

        if (l > r) {
            swap(l, r);
        }

        l++, r--;

        long long k = __lg(r - l + 1);

        if (max(st[k][l], st[k][r - (1 << k) + 1]) > a[l - 1]) {
            tong--;
        }
    }

    cout << tong << endl;
    // system("cls");

    // for (long long i = 0; i < n; i++) {
    //     for (long long j = 0; j < n; j++) cout << st[i][j] << " ";
    //     cout << endl;
    // }
}
