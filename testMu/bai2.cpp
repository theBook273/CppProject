#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n, a[3];
        cin >> n >> a[0] >> a[1] >> a[2];

        int tong = (a[0] + a[1] + a[2]);

        int temp = n / tong;
        tong = temp * tong;
        temp *= 3;
        while(n > tong) {
            temp++;
            tong += a[temp % 3 - 1];
        }
        cout << temp << endl;

    }
}
