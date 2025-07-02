#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        long long tong = 0;
        for (long long i = 0; i < n; ++i) {
            long long temp;
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
