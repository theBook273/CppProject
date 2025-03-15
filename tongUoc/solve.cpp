#include <bits/stdc++.h>

using namespace std;
// using int = long long;

const int mod = 1e9 + 7;

int prime[1000005], congDon[1000005];

int primeNum(int n) {
    int temp = prime[n];
    int tong = 0;

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

    for (int i = 2; i * i <= 1e6; i++) {
        if (prime[i] == 0) {
            for (int j = i; j * i <= 1e6; j++)
                if (prime[i * j] == 0) prime[j * i] = i;
        }
    }

    for (int i = 2; i <= 1e6; i++) {
        if (prime[i] == 0) {
            prime[i] = i;
        }
    }

    congDon[0] = 0;
    congDon[1] = 0;

    for (int i = 2; i <= 1e6; i++) {
        congDon[i] = (congDon[i - 1] + primeNum(i)) % mod;
    }

    // cout << congDon[99] << endl;

    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        cout << congDon[r] - congDon[l - 1] << "\n";
    }
}
