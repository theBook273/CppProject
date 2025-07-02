#include <bits/stdc++.h>

using namespace std;

const long long maxn = 5 * 1e5 + 9;

long long n, a[maxn];
long long cou[maxn + 90];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;

    for (long long i(0); i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> uc;

    for (long long i(1); i <= sqrt(n); ++i) {
        if (n % i == 0) {
            uc.push_back(i);
            if (n / i != i) {
                uc.push_back(n / i);
            }
        }
    }

    sort(uc.begin(), uc.end());

    unordered_map<long long, long long> vl;
    vector<long long> compress;

    for (long long i = 0; i < n; i++) {
        if (!vl.count(a[i])) {
            vl[a[i]] = vl.size();
        }
        compress.push_back(vl[a[i]]);
    }

    cout << uc.size() << "\n";

    long long current = 1;

    for (auto i : uc) {
        long long l(0), res(1e9);
        long long unique = 0;

        for (long long r = 0; r < n; r++) {
            if (cou[compress[r]] != current) {
                cou[compress[r]] = current;
                unique++;
            }
            if (r - l + 1 == i) {
                res = min(res, unique);
                unique = 0;
                current++;
                l = r + 1;
            }
        }

        cout << i << " " << res << "\n";
    }
}
