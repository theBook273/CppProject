#include <bits/stdc++.h>
#define int unsigned long long

using namespace std;

const int maxn = 1e6 + 20;

int a[maxn];

signed main() {
    freopen("TROCHOI.INP", "r", stdin);
    freopen("TROCHOI.OUT", "w", stdout);
    int n;
    cin >> n;
    int tong = 0;
    map<int, int> soluong;
    for (int i = 0; i < n; ++i) {
        int temp;
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