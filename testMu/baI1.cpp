#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        int a[n],b[n];

        for(auto &i : a) cin >> i;
        for(auto &i : b) cin >> i;

        int s,m;
        s = m = 0;
        s += a[n - 1];

        for(int i = 0; i < n - 1; i++) {
            if(a[i] > b[i + 1]) {
                s += a[i];
                m += b[i + 1];
            }
        }

        cout << s - m << endl;
    }
}
