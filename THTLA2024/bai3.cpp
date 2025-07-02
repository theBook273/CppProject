#include <bits/stdc++.h>
#define long long unsigned long long

using namespace std;

const long long maxn = 1e6 + 20;

long long a[maxn];

signed main() {
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long tong = 0;
    map<long long, long long> soluong;
    for (long long i = 0; i < n; ++i) {
        long long temp;
        cin >> temp;
        tong += temp;
        soluong[temp & 1]++;
    }

    if (tong & 1) {
        cout << soluong[0] * soluong[1];
    } else {
        cout << (soluong[0] * (soluong[0] - 1) / 2) +
                    (soluong[1] * (soluong[1] - 1) / 2);
    }
}
