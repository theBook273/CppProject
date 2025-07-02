#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long a[100000];

main() {
    long long n;
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (long long t = 0; t < n; t++) {
        long long res = 0;
        for (long long i = 1; i <= n; i++) {
            long long minR = 1e9;
            for (long long j = i; j <= i + t; j++) {
                minR = min(minR, a[j]);
            }
            res = max(res, minR);
        }
        cout << res << " ";
    }
}
