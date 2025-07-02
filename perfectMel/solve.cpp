#include <bits/stdc++.h>
#define long long long long

using namespace std;
long long n, a[100000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long sig = 1;
        string out[2] = {"NO", "YES"};

        for (long long i = 0; i < n - 1; i++) {
            long long temp = abs(a[i + 1] - a[i]);
            if (temp != 5 && temp != 7) {
                sig = 0;
            }
        }

        cout << out[sig] << endl;
    }
}
