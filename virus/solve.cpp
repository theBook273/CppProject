#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long mod = 1e9 + 7;

long long a[1000000];

main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;

    a[0] = n;
    a[1] = n * 2;
    long long tongtemp = a[1] + a[0];

    for (long long i = 2; i <= k; i++) {
        a[i] += tongtemp + a[i - 1];
        tongtemp += a[i];
        tongtemp %= mod;
        a[i] %= mod;
    }

    cout << a[k];
}
