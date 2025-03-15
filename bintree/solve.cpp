#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100000];

int bst(int x) {
    int tong = 0;
    for (int i = 0, j = x; i <= x, j >= 0; i++, j--) {
        tong += ((a[i] % 1855180120) * (a[j] % 1855180120)) % 1855180120;
        tong %= 1855180120;
    }
    return tong % 1855180120;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    freopen("bst.inp", "r", stdin);
    freopen("bst.out", "w", stdout);
    int n;
    cin >> n;

    a[0] = 1;
    a[1] = 1;

    for (int i = 2; i <= n; i++) {
        a[i] = bst(i - 1);
    }

    cout << a[n];
}