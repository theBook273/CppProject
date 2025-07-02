#include <bits/stdc++.h>

using namespace std;
// using long long = long long;

const long long mod = 1e9 + 7;

long long prime[1000005], congDon[1000005];

long long primeNum(long long n) {
    long long temp = prime[n];
    long long tong = 0;

    tong += prime[n];

    while (n != 1) {
        n /= prime[n];
        // cout << prime[n] << endl;
        if (prime[n] != temp) {
            temp = prime[n];
            tong += temp;
        }
    }
    return tong;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("sumdiv.inp", "r", stdin);
    // freopen("sum.out", "w", stdout);

    prime[0] = prime[1] = 0;

    for (long long i = 2; i * i <= 1e6; i++) {
        if (prime[i] == 0) {
            for (long long j = i; j * i <= 1e6; j++)
                if (prime[i * j] == 0) prime[j * i] = i;
        }
    }

    for (long long i = 2; i <= 1e6; i++) {
        if (prime[i] == 0) {
            prime[i] = i;
        }
    }

    congDon[0] = 0;
    congDon[1] = 0;

    for (long long i = 2; i <= 1e6; i++) {
        congDon[i] = (congDon[i - 1] + primeNum(i)) % mod;
    }

    // cout << congDon[99] << endl;

    long long t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        cout << congDon[r] - congDon[l - 1] << "\n";
    }
}
