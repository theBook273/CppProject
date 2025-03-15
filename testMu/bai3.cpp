#include<bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int a[m];
        unordered_map<int,int> mp;


        for(auto &i : a) cin >> i;

        for(int i = 0; i < k; i++) {
            int temp;
            cin >> temp;
            mp[temp]++;
        }

        if(mp.size() < n - 1) {
            for(int i = 0; i < m; i++) cout << 0;
        } else if(mp.size() == n) {
            for(int i = 0; i < m; i++) cout << 1;
        } else {
            for(int i : a) {
                if(mp.count(i)) cout << 0;
                else cout << 1;
            }
        }

        cout << endl;
    }
}
