#include <bits/stdc++.h>
#define int long long

using namespace std;

int a[100000];

main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int t = 0; t < n; t++) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            int minR = 1e9;
            for (int j = i; j <= i + t; j++) {
                minR = min(minR, a[j]);
            }
            res = max(res, minR);
        }
        cout << res << " ";
    }
}