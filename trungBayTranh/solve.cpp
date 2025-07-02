#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> a[500009];
long long n;
long long prefix[500009];

long long check(long long i, long long j) {
    if (a[j].first - a[i].first <= prefix[j] - prefix[i - 1]) return 1;
    return 0;
}

long long main() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a, a + n);

    prefix[0] = 0;

    for (long long i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1].second;
    }

    long long res = 0;

    for (long long l = 0; l < n; l++) {
        long long r = n - 1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(l, mid)) {
                res = max(res, prefix[mid] - prefix[l - 1] -
                                   (a[mid].first - a[l].first));
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    cout << res << endl;
}
