#include<bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    long long t;
    cin >> t;

    while(t--) {
        long long n,x,y, tong = 0, res = 0;
        cin >> n >> x >> y;

        long long a[n];

        for(long long &i : a) {
            cin >> i;
            tong += i;
        }

        sort(a, a + n);

        for(long long i = 0; i < n; i++) {
            for(long long j = i + 1; j < n; j++) {
                long long temp = tong - a[i] - a[j];
                if(x <= temp && temp <= y) res++;
            }
        }

        cout << res << endl;
    }
}
