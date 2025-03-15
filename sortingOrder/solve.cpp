#include <bits/stdc++.h>

using namespace std;

long long n, a[1000000], b[1000000];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }

    pair<long long, long long> res;

    for (long long r = n - 1; r > 0; r--) {
        if (b[r - 1] <= b[r]) {
            long long l = r;
            while (b[l - 1] <= b[l] && l - 1 >= 0) {
                l--;
                if (r - l + 1 > res.second - res.first + 1) {
                    res.first = l;
                    res.second = r;
                }
            }
            r = l + 1;
        }
    }
    cout << res.first + 1 << " " << res.second + 1 << endl;
}