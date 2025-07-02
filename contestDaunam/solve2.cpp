#include <bits/stdc++.h>
#define long long long long

using namespace std;

const long long maxn = 2 * 1e5 + 8;

map<long long, long long> mp;
long long n, k;

bool check(long long t) {
    long long extra = 0;

    for (long long i = 1; i <= n; i++) {
        if (mp[i] > t) extra += mp[i] - t;
    }

    long long need = 0;
    for (long long i = 1; i <= n; i++) {
        if (mp[i] < t) need += (t - mp[i]) / 2;
    }

    return need >= extra;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;

    for (long long i = 0; i < k; i++) {
        long long temp;
        cin >> temp;
        mp[temp]++;
    }

    long long left = 1, right = k * 2;
    long long res = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;
        if (check(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res << endl;
}
