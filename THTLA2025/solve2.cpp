#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e5 + 20;

long long a[maxn];
long long leftmin[maxn], rightmin[maxn];
long long tong = 0;

signed main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        tong += a[i];
    }

    long long sum = a[0];
    long long minsing = sum;
    long long mincurrent = sum;

    for (long long i = 1; i < n; ++i) {
        sum = min(a[i], a[i] + sum);
        mincurrent = min(mincurrent, sum);
        minsing = min(minsing, mincurrent);
    }

    cout << minsing;
}
