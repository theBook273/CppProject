#include <bits/stdc++.h>

using namespace std;

int n, m;

long long sum(long long a[], long long d) {
    long long tong = 0, check = 0;

    if (d == 1) return accumulate(a, a + n, 0);

    for (int i = 0; i < n; i++) {
        if (check == d && n - i >= d) check = 0;
        tong += (max(a[i] - check, 0ll));
        // cout << check << " " << a[i] << " " << tong << " \n";
        check++;
    }

    return tong;
}

int main() {
    cin >> n >> m;

    long long a[n];

    for (auto &i : a) {
        cin >> i;
    }

    sort(a, a + n, greater<int>());

    if (m > accumulate(a, a + n, 0)) {
        cout << "IMPOSSIBLE";
        return 0;
    }

    long long l = 1, r = n, ans = -1;

    while (l <= r) {
        long long mid = (l + r) / 2;
        if (n / mid < mid) {
            r = mid - 1;
            // cout << r;
            continue;
        }
        if (sum(a, mid) >= m) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}