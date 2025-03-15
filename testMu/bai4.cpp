#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--) {
        int n,x,y, tong = 0, res = 0;
        cin >> n >> x >> y;

        int a[n];

        for(int &i : a) {
            cin >> i;
            tong += i;
        }

        sort(a, a + n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp = tong - a[i] - a[j];
                if(x <= temp && temp <= y) res++;
            }
        }

        cout << res << endl;
    }
}
