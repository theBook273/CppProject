#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll a[100000];
signed main() {
    cin.tie(NULL)->sync_with_stdio();
    ll n, tong = 0;

    cin >> n;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        tong += a[i];
    }

    sort(a, a + n);

    int l = 0, r = n - 1;

    while (l <= r) {
        tong += a[r] - a[l];
        l++;
        r--;
    }

    cout << tong;
}