#include <bits/stdc++.h>

using namespace std;

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        int res = 1e9;

        for (char maxc = 'a'; maxc <= 'z'; maxc++) {
            int dem = 0;

            int l = 0;

            for (int r = 0; r < s.size(); r++) {
                if (s[r] == maxc) {
                    dem = max(dem, r - l);
                    while (s[r] == maxc) r++;
                    l = r;
                }
            }

            dem = max(dem, int(s.size() - l));

            int cnt = 0;
            while (dem) {
                cnt++;
                dem -= ceil(dem / 2.0);
            }
            res = min(res, cnt);
        }
        cout << res << "\n";
    }
}