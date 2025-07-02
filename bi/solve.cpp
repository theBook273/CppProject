#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;

    while (t--) {
        map<long long, long long> mp;
        long long n;
        cin >> n;

        for (long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            mp[a]++;
        }

        long long res = 0;
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
