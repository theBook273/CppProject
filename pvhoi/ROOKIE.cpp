#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m, q;
vector<pair<int,int>> pos;

namespace sub3 {

void process(vector<vector<int>> &a, int x, int y) {
    int avail = 0;

    if(a[x][y] == 2) {
        a[x][y] = 0;
    } else if(a[x][y] == 0) {
        a[x][y] = 2;
    }

    for(int i = 1; i <= n; i++) {
        if(a[i][y] != 2) {
            a[i][y] ^= 1;
        }
    }

    for(int i = 1; i <= m; i++) {
        if(a[x][i] != 2) {
            a[x][i] ^= 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            avail += ((a[i][j] == 1));
        }
    }
    cout << avail;
    cout << "\n";
}

signed solve() {
    vector<vector<int>> board(n + 1, vector<int>(m + 1, 0));

    for(auto [x,y] : pos) {
        process(board, x, y);
    }

    return 0;
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ROOKIE.INP", "r", stdin);
    freopen("ROOKIE.OUT", "w", stdout);

    cin >> n >> m >> q;
    for(int x, y, i = 0; i < q; i++) {
        cin >> x >> y;
        pos.push_back({x,y});
    }

    return sub3::solve();
}
