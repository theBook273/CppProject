#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        vector<ll> a;

        cin >> n;

        ll cnt[n + 1], res[n + 1];

        memset(cnt, 0, sizeof(cnt));
        memset(res, 0, sizeof(cnt));

        for (ll i = 0; i < n; i++) {
            ll temp;
            cin >> temp;
            if (temp <= n) cnt[temp]++;
        }

        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 0)
                for (int j = i; j <= n; j += i) res[j] += cnt[i];
        }
        cout << *max_element(res + 1, res + n + 1) << endl;
    }
}