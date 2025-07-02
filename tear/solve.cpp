#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        long long res = 1e9;

        for (char maxc = 'a'; maxc <= 'z'; maxc++) {
            long long dem = 0;

            long long l = 0;

            for (long long r = 0; r < s.size(); r++) {
                if (s[r] == maxc) {
                    dem = max(dem, r - l);
                    while (s[r] == maxc) r++;
                    l = r;
                }
            }

            dem = max(dem, long long(s.size() - l));

            long long cnt = 0;
            while (dem) {
                cnt++;
                dem -= ceil(dem / 2.0);
            }
            res = min(res, cnt);
        }
        cout << res << "\n";
    }
}
