#include <bits/stdc++.h>
#define int long long

using namespace std;

int temp, res = 0, k1, k2, pred, coins, cx;
vector<pair<int, int>> flo;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) cin >> temp, flo.push_back({temp, 0});
        for (auto &i : flo) cin >> i.second;

        sort(flo.begin(), flo.end());

        for (int i = 0; i < n; i++) {
            k1 = min(m / flo[i].first, flo[i].second);
            pred = flo[i].first * k1;
            flo[i].second -= k1;
            coins = m - pred;

            if (i + 1 < n && flo[i + 1].first - flo[i].first == 1) {
                cx = flo[i + 1].second;
                if (coins >= flo[i + 1].first) {
                    k2 = min(coins / flo[i + 1].first, flo[i + 1].second);
                    pred += k2 * flo[i + 1].first;
                    cx -= k2;
                    coins = m - pred;
                }
                pred += min(min(coins, cx), k1);
            }
            res = max(res, pred);
        }
        cout << res << endl;
        res = 0;
        flo.clear();
    }
}