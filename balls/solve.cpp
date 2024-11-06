#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
int a[1000006];
int res[1000006], minN[1000006];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i <= n; i++) {
        minN[i] = 1e9;
    }

    res[0] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        res[i] = min(res[i - 1] + 1, minN[a[i]]);
        minN[a[i]] = min(minN[a[i]], res[i - 1]);
    }

    cout << n - res[n] << '\n';
}