#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e5 + 8;

map<int, int> mp;
int n, k;

bool check(int t) {
    int extra = 0;

    for (int i = 1; i <= n; i++) {
        if (mp[i] > t) extra += mp[i] - t;
    }

    int need = 0;
    for (int i = 1; i <= n; i++) {
        if (mp[i] < t) need += (t - mp[i]) / 2;
    }

    return need >= extra;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        mp[temp]++;
    }

    int left = 1, right = k * 2;
    int res = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << res << endl;
}