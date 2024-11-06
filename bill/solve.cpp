#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        int res = 0;
        if (k != 0) {
            k -= n;
            res++;
            for (int i = n - 1; i >= 1; i--) {
                if (k <= 0) break;
                k -= i;
                res++;
                if (k <= 0) break;
                k -= i;
                res++;
                if (k <= 0) break;
            }
        }

        cout << res << endl;
    }
}