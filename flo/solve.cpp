#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        int check = m;

        int a[n];

        map<int, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }

        int res = 0, temp = 0;

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