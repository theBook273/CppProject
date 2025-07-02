#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 20;

int a[maxn];
int leftmin[maxn], rightmin[maxn];
int tong = 0;

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tong += a[i];
    }

    int sum = a[0];
    int minsing = sum;
    int mincurrent = sum;

    for (int i = 1; i < n; ++i) {
        sum = min(a[i], a[i] + sum);
        mincurrent = min(mincurrent, sum);
        minsing = min(minsing, mincurrent);
    }

    cout << minsing;
}