#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int tong = 0;
        for (int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            tong += temp;
        }
        if (tong == x * n)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}