#include <bits/stdc++.h>

using namespace std;

long long main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        long long ans = a.size() + b.size();
        for (long long i = 0; i < b.size(); i++) {
            long long dem = i;
            for (auto c : a) {
                if (dem < b.size() && c == b[dem]) ++dem;
            }
            ans = min(ans, long long(a.size() + b.size() - (dem - i)));
        }
        cout << ans << "\n";
    }
}
