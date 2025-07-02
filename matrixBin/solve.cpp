#include <bits/stdc++.h>

using namespace std;

const long long maxn = 127;

char a[maxn][maxn];
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    long long t;
    cin >> t;
    while (t--) {
        map<long long, long long> demhang, demcot;
        long long n, m;
        cin >> n >> m;

        for (long long i = 0; i < n; i++)
            for (long long j = 0; j < m; j++) cin >> a[i][j];

        for (long long i = 0; i < n; ++i) {
            for (long long j = 0; j < m; ++j) {
                demhang[i] += (a[i][j] == '1');
            }
        }

        for (long long j = 0; j < m; ++j) {
            for (long long i = 0; i < n; ++i) {
                demcot[j] += (a[i][j] == '1');
            }
        }

        long long cnt1, cnt2;
        cnt1 = cnt2 = 0;

        for (auto [i, j] : demhang) {
            cnt1 += (j % 2);
        }
        for (auto [i, j] : demcot) {
            cnt2 += (j % 2);
        }

        cout << max(cnt1, cnt2) << "\n";
    }
}
