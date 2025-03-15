#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;

int a[1000000];

main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;

    a[0] = n;
    a[1] = n * 2;
    int tongtemp = a[1] + a[0];

    for (int i = 2; i <= k; i++) {
        a[i] += tongtemp + a[i - 1];
        tongtemp += a[i];
        tongtemp %= mod;
        a[i] %= mod;
    }

    cout << a[k];
}