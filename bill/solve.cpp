#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long res = 0;
        if (k != 0) {
            k -= n;
            res++;
            for (long long i = n - 1; i >= 1; i--) {
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
