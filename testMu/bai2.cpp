#include<bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    long long t;
    cin >> t;

    while(t--) {
        long long n, a[3];
        cin >> n >> a[0] >> a[1] >> a[2];

        long long tong = (a[0] + a[1] + a[2]);

        long long temp = n / tong;
        tong = temp * tong;
        temp *= 3;
        while(n > tong) {
            temp++;
            tong += a[temp % 3 - 1];
        }
        cout << temp << endl;

    }
}
