#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll m, n, k;
vector<ll> a;

bool check(int dis) {
    for (int i = 1; i < a.size(); i++) {
        if (a[i] < dis)
            return false;
        else
            dis = a[i] + dis;
    }
    return true;
}

signed main() {
    // freopen("supermar.inp", "r", stdin);
    // freopen("supermar.out", "w", stdout);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    int l = 1, r = 1e9;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
}