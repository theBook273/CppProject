#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long a[100006], mark[100006];

signed main() {
    freopen("PTB2.INP", "r", stdin);
    freopen("PTB2.OUT", "w", stdout);
    long long n, res = 0;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
        mark[a[i]] = 1;
    }

    sort(a, a + n);

    for (long long i = 0; i < n; i++) {
        for (long long j = i + 1; j < n; j++) {
            long long temp = -(a[i] - a[j]);
            if (mark[temp] == 1 && temp != a[j] && temp > a[i]) res += 2;
        }
    }
    cout << res;
}
