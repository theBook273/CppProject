#include <bits/stdc++.h>

using namespace std;

long long main() {
    long long q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;

        long long tong = 0, maxN = 0, a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];

            if (a[i] == 0) {
                tong++;
                maxN = max(maxN, tong);
            }
            if (a[i] == 1) {
                tong = 0;
            }
        }
        cout << maxN;
    }
}
