#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5 * 1e4 + 8;

int a[maxn];
int n, k;

bool check(int x, int pizz) {
    int temp1 = a[n - 1];

    temp1 += x;
    pizz -= x;

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] * 2 < temp1) {
            int sub = ceil(temp1 / 2.0) - a[i];
            if (pizz - sub >= 0) {
                temp1 = a[i] + sub;
                pizz -= sub;
            } else {
                return 0;
            }
        } else
            return 1;
    }
    return 1;
}

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (k--) {
        int pizza;
        cin >> pizza;
        int left = 0, right = pizza;
        int res = a[n - 1];
        while (left <= right) {
            int mid = (right + left) / 2;
            if (check(mid, pizza)) {
                res = mid + a[n - 1];
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << res << " ";
    }
}