#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long n, m;

    cin >> n >> m;

    long long a[n], tong = m;

    vector<long long> maxV;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n - 1; i++) {
        maxV.push_back(max(a[i], a[i + 1]));
    }

    // for (auto i : maxV) {
    //     cout << i << " ";
    // }

    for (long long j = 0; j < m; j++) {
        long long l, r, mi = -1e9;

        cin >> l >> r;

        if (l > r) {
            swap(l, r);
        }

        for (long long i = l - 1; i < r - 1; i += 2) {
            mi = max(maxV[i], mi);
        }

        if (mi > a[l - 1]) {
            tong--;
        }
    }
    cout << tong << endl;
}
