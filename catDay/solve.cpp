#include <bits/stdc++.h>

using namespace std;

long long n, a[1000][1000], dis = 0, res = 1e9, dem = 0;
bool visit[10];
vector<long long> v, resV;
void solve() {
    if (v.size() == n) {
        // dem++;
        // if (dem >= 1000000) return;
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
        dis = 0;
        for (long long i = 1; i < v.size(); i++) {
            dis += a[v[i - 1]][v[i]];
        }
        res = min(res, dis);
        return;
    }
    for (long long i = 1; i <= n; i++) {
        if (!visit[i]) {
            visit[i] = true;
            v.push_back(i);
            solve();
            visit[i] = false;
            v.pop_back();
        }
    }
}

signed main() {
    cin.tie()->sync_with_stdio(false);
    cin >> n;

    for (long long i = 1; i <= n; i++) {
        for (long long j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    solve();
    cout << res << endl;
}
