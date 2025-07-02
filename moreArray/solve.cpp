#include <bits/stdc++.h>

using namespace std;

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        set<long long> s;
        long long n;
        cin >> n;
        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            s.insert(temp);
        }

        vector<long long> a;
        for (auto i : s) a.push_back(i);

        if (a.size() == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long dp[a.size() + 1];

        dp[0] = 0;
        dp[1] = 1;

        for (long long i = 2; i <= a.size(); ++i) {
            if (a[i - 2] + 1 == a[i - 1]) {
                dp[i] = max(dp[i - 2] + 1, dp[i - 1]);
            } else {
                dp[i] = dp[i - 1] + 1;
            }
        }

        cout << dp[a.size()] << "\n";
    }
}
