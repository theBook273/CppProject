#include <bits/stdc++.h>

using namespace std;
int n, k;
int a[220];

bool check(int dis) {
    int cnt = 0;
    int current = 0;
    while (current < n) {
        cnt++;
        int target = a[current] + dis;
        int j = upper_bound(a + current, a + n, target) - a - 1;
        current = upper_bound(a + j, a + n, a[j] + dis) - a;
    }
    return cnt <= k;
}

signed main() {
    ifstream fin("BUS.INP");
    ofstream fout("BUS.OUT");

    cin >> n >> k;

    for (int i = 0; i < n; ++i) cin >> a[i];

    int l = 0, r = a[n - 1] - a[0] + 1, res = r;

    while (l <= r) {
        int m = (l + r) / 2;
        if (check(m)) {
            res = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    cout << res << endl;
}