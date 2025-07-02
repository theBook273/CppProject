#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, k, res, a[100000];
vector<long long> v;

void chose(long long x, long long lim) {
    if (v.size() == lim) {
        for (long long i = 0; i < v.size(); ++i) {
            for (long long j = i + 1; j < v.size(); ++j) {
                if ((v[i] + v[j]) % k == 0) {
                    return;
                }
            }
        }
        res = max(res, lim);
        return;
    }
    for (long long i = x + 1; i < n; ++i) {
        v.push_back(a[i]);
        chose(i, lim);
        v.pop_back();
    }
}

main() {
    cin >> n >> k;

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (long long i = 1; i <= n; ++i) {
        chose(-1, i);
    }

    cout << res;
}
