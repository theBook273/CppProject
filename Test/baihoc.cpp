#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k;

    cin >> n >> k;

    long long a[n];
    long long f[n + 3];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        f[i] = 2 * 1e9;
    }

    f[0] = 0;
    f[1] = f[0] + abs(a[1] - a[0]);

    for (long long i = 2; i < n; i++) {
        for (long long j = 1; j <= k; j++) {
            if (i - j >= 0) {
                f[i] = min(f[i], f[i - j] + abs(a[i] - a[i - j]));
            }
        }
    }

    cout << f[n - 1];
}