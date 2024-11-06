#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100006], mark[100006];

signed main() {
    freopen("PTB2.INP", "r", stdin);
    freopen("PTB2.OUT", "w", stdout);
    int n, res = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mark[a[i]] = 1;
    }

    sort(a, a + n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = -(a[i] - a[j]);
            if (mark[temp] == 1 && temp != a[j] && temp > a[i]) res += 2;
        }
    }
    cout << res;
}