#include <bits/stdc++.h>

using namespace std;

const int maxn = 5 * 1e5 + 27;

int a[maxn];
int n, k;
string s;
pair<int, pair<int, char>> ind[maxn];

bool check(int x) {
    bool mark[maxn];
    memset(mark, 0, sizeof(mark));
    if (ind[x].second.second == 'B') {
        mark[ind[x].second.first] = 1;
        int l = 1e9, r = -1e9;
        for (int i = x; i < n; ++i) {
            if (ind[i].second.second == 'B') {
                l = min(l, ind[i].second.first);
                r = max(r, ind[i].second.first);
            } else {
                mark[ind[i].second.first] = 1;
            }
        }

        int dem = 0;

        for (int i = l + 1; i < r; ++i) {
            if (mark[i]) {
                dem++;
            }
        }

        if (dem != 0) return (dem + 1 <= k);
        return 1;
    }
    if (ind[x].second.second == 'R') {
        int l = ind[x].second.first;
        int r = ind[x].second.first;
        for (int i = x; i < n; ++i) {
            if (ind[i].second.second == 'B') {
                l = min(l, ind[i].second.first);
                r = max(r, ind[i].second.first);
            } else {
                mark[ind[i].second.first] = 1;
            }
        }

        int dem = 0;
        for (int i = l + 1; i < r; ++i) {
            if (mark[i]) dem++;
        }
        return (dem + 1 <= k);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // int t;
    // cin >> t;
    // while (t--) {
    cin >> n >> k;
    cin >> s;
    int dem = 0;

    for (int i = 0; i < n; ++i) {
        cin >> ind[i].first;
        ind[i].second.first = i;
        ind[i].second.second = s[i];
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            dem++;
            while (s[i + 1] == 'B') {
                i++;
            }
        }
    }

    if (dem <= k) {
        cout << 0 << "\n";
        return 0;
    }

    sort(ind, ind + n);

    int res = INT_MAX;

    int l = 0, r = n - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            res = min(res, ind[m].first);
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << res << "\n";
    // }
}