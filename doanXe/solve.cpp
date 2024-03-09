#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int a[1000000];
int n, m, k;

bool check(int x) {
    int pre = 1, dem = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[pre] > x || i - pre + 1 > k) {
            pre = i;
            dem++;
        }
    }
}

signed main() {
    cin >> n >> m >> k;

    k = ceil(n / m * 1.0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int l = 1, r = 1e9, res = 0;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else
            l = mid + 1;
    }

    cout << res << endl;
}