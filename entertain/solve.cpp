#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class solution {
   private:
    long long n, a[100000], dp[100000], cnt[100000];

   public:
    solution() {
        cin >> n;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
    }

    void dpIt() {
        dp[1] = cnt[1];
        for (long long i = 2; i <= *max_element(a, a + n); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] * cnt[i] * i);
        }
    }

    void solve() {
        dpIt();
        cout << dp[*max_element(a, a + n)];
    }
};

signed main() {
    solution a;
    a.solve();
}
