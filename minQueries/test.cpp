#include <bits/stdc++.h>

using namespace std;

long long a[1000], st[1000][1000];
long long n;
long long main() {
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];

        st[0][i] = a[i];
    }

    for (long long i = 1; i * 2 < n; i++) {
        for (long long j = 0; j + 1 < n; j++) {
            st[i][j] = max(st[i - 1][j], st[i - 1][j + 1]);
        }
    }

    for (long long i = 0; i * 2 < n; i++) {
        for (long long j = 0; j < n; j++) {
            cout << st[i][j] << " ";
        }
        cout << "\n";
    }
}
