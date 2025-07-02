#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, cnt[400009], sum[400009], l[400009], r[400009];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);

    long long t;
    cin >> t;
    while (t--) {
        cin >> n;

        long long temp = 0;

        for (long long i = 1; i <= 2 * n; ++i) sum[i] = cnt[i] = 0;

        for (long long i = 1; i <= n; i++) {
            cin >> l[i] >> r[i];
            temp = max(max(l[i], r[i]), temp);
            if (l[i] == r[i]) {
                sum[l[i]] = 1;
                cnt[l[i]]++;
            }
        }

        for (long long i = 2; i <= temp; i++) {
            sum[i] += sum[i - 1];
        }

        for (long long i = 1; i <= n; i++) {
            if ((l[i] == r[i] && cnt[l[i]] <= 1) ||
                (l[i] != r[i] && sum[r[i]] - sum[l[i] - 1] < r[i] - l[i] + 1))
                cout << 1;
            else
                cout << 0;
        }
        cout << endl;
    }
}
