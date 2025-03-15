#include <bits/stdc++.h>

using namespace std;
int n;
int a[200007], b[200007];

bool solve(int x) {
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (cnt <= b[i] && x - cnt - 1 <= a[i]) {
            cnt++;
        }
    }
    return cnt >= x;
}

int main() {
    cin >> n;

    int l = 1, r = n, res = 0;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    while (l <= r) {
        int m = (l + r) / 2;
        if (solve(m)) {
            res = m;
            l = m + 1;
        } else
            r = m - 1;
    }

    cout << res;
}