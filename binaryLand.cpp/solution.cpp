#include <bits/stdc++.h>

using namespace std;

template <typename T = long long>
vector<T> create(size_t n) {
    return vector<T>(n);
}

template <typename T, typename... Args>
auto create(size_t n, Args... args) {
    return vector<decltype(create<T>(args...))>(n, create<T>(args...));
}

const long long mod = 1'000'000'007;

const long long maxq = 300000, maxn = 20;

long long w[2][maxq][maxn][maxn], stk[2];

string p[2][maxq];

long long main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, C, Q;
    cin >> N >> Q;
    auto upd_back = [&](long long id) {
        long long n = stk[id];
        if (n >= 2) {
            for (long long i = 0; i < N; i++) {
                for (long long j = 0; j < N; j++) w[id][n - 1][i][j] = 0;
                for (long long j = i - 1; j <= i + 1; j++) {
                    if (j < 0 || j >= N) continue;
                    if (p[id][n - 1][i] != p[id][n - 2][j]) continue;
                    for (long long k = 0; k < N; k++) {
                        w[id][n - 1][i][k] += w[id][n - 2][j][k];
                        if (w[id][n - 1][i][k] >= mod)
                            w[id][n - 1][i][k] -= mod;
                    }
                }
            }
        } else if (n == 1) {
            for (long long i = 0; i < N; i++)
                for (long long j = 0; j < N; j++) w[id][0][i][j] = i == j;
        }
    };

    while (Q--) {
        string ty;
        cin >> ty;
        if (ty[0] == 'a') {
            string s;
            cin >> s;
            p[1][stk[1]++] = s;
            upd_back(1);
        } else if (ty[0] == 'r') {
            if (stk[0] == 0) {
                while (stk[1]) {
                    p[0][stk[0]++] = p[1][--stk[1]];
                    upd_back(0);
                }
            }
            stk[0]--;
        } else {
            long long i, j;
            cin >> i >> j;
            i--;
            j--;
            if (stk[1] == 0) {
                cout << w[0][stk[0] - 1][i][j] << '\n';
            } else if (stk[0] == 0) {
                cout << w[1][stk[1] - 1][j][i] << '\n';
            } else {
                long long ans = 0;
                for (long long k = 0; k < N; k++) {
                    for (long long k2 = k - 1; k2 <= k + 1; k2++) {
                        if (k2 < 0 || k2 >= N) continue;
                        if (p[0][0][k] != p[1][0][k2]) continue;
                        if (!w[0][stk[0] - 1][i][k]) continue;
                        if (!w[1][stk[1] - 1][j][k2]) continue;
                        ans += (1ll * w[0][stk[0] - 1][i][k] *
                                w[1][stk[1] - 1][j][k2]) %
                               mod;
                        if (ans >= mod) ans -= mod;
                    }
                }
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
