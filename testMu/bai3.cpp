#include<bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    long long t;
    cin >> t;
    while(t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long a[m];
        unordered_map<long long,long long> mp;


        for(auto &i : a) cin >> i;

        for(long long i = 0; i < k; i++) {
            long long temp;
            cin >> temp;
            mp[temp]++;
        }

        if(mp.size() < n - 1) {
            for(long long i = 0; i < m; i++) cout << 0;
        } else if(mp.size() == n) {
            for(long long i = 0; i < m; i++) cout << 1;
        } else {
            for(long long i : a) {
                if(mp.count(i)) cout << 0;
                else cout << 1;
            }
        }

        cout << endl;
    }
}
