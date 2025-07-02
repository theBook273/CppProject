#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long mp[100000];
long long n, k, a[100000], res = 0;

main() {
    cin >> n >> k;

    for (long long i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i] % k]++;
    }

    mp[0] = min(mp[0], (long long)1);
    if (k % 2 == 0) mp[k / 2] = min(mp[k / 2], (long long)1);

    for (long long i = 0; i <= k / 2; ++i) {
        res += max(mp[i], mp[k - i]);
    }

    cout << res;
}
