#include <bits/stdc++.h>
#define int long long

using namespace std;
int mp[100000];
int n, k, a[100000], res = 0;

main() {
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i] % k]++;
    }

    mp[0] = min(mp[0], (int)1);
    if (k % 2 == 0) mp[k / 2] = min(mp[k / 2], (int)1);

    for (int i = 0; i <= k / 2; ++i) {
        res += max(mp[i], mp[k - i]);
    }

    cout << res;
}