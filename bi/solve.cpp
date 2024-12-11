#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        map<int, int> mp;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            mp[a]++;
        }

        int res = 0;
        bool check = 0;

        for (auto i : mp) {
            if (i.second > 1) res++;
            if (i.second == 1 && check == 0) {
                res += 2;
                check = 1;
            } else if (i.second == 1 && check == 1) {
                check = 0;
            }
        }

        cout << res << endl;
    }
}