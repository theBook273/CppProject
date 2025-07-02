
#include <bits/stdc++.h>

using namespace std;

long long fibo[10000];

long long solve(long long n, long long k) {
    if (k == (long long)pow(2, n - 1)) return n;

    if (k <= fibo[n - 1])
        return solve(n - 1, k);
    else if (k - fibo[n - 1] - 1 <= fibo[n - 1])
        return solve(n - 1, k - fibo[n - 1] - 1);

    return 0;
}

long long main() {
    for (long long i = 1; i <= 50; i++) {
        fibo[i] = (long long)pow(2, i) - 1;
    }

    // long long t;

    // cin >> t;

    // while (t--) {
    long long n, k;

    cin >> n >> k;

    cout << solve(n, k) << endl;
    // }
}
