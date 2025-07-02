#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long a[100000];

long long bst(long long x) {
    long long tong = 0;
    for (long long i = 0, j = x; i <= x, j >= 0; i++, j--) {
        tong += ((a[i] % 1855180120) * (a[j] % 1855180120)) % 1855180120;
        tong %= 1855180120;
    }
    return tong % 1855180120;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    freopen("bst.inp", "r", stdin);
    freopen("bst.out", "w", stdout);
    long long n;
    cin >> n;

    a[0] = 1;
    a[1] = 1;

    for (long long i = 2; i <= n; i++) {
        a[i] = bst(i - 1);
    }

    cout << a[n];
}
