#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long c[100000];

main() {
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < m; i++) {
        cin >> c[i];
    }

    long long res = 1e9;

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < m; j++) {
            if (abs(c[j] - i) > 0) res = min(res, abs(c[i] - i));
        }
    }

    cout << res;
}
