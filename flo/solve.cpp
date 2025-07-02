#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        long long check = m;

        long long a[n];

        map<long long, long long> mp;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        long long res = 0, temp = 0;

        for (auto i : mp) {
            m = check;
            temp = 0;
            if (m / i.first >= i.second) {
                temp += (i.first * i.second);
            } else {
                temp += (m / i.first) * i.first;
            }
            m -= temp;

            if (mp.count(i.first - 1)) {
                if (m / (i.first - 1) >= mp[i.first - 1]) {
                    temp += (i.first - 1) * mp[i.first - 1];
                } else {
                    temp += (m / (i.first - 1)) * mp[i.first - 1];
                }
                m -= temp;
            }

            res = max(res, temp);
        }
        cout << res << endl;
    }
}
