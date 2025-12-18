#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, e, k;
vector<pair<int,int>> app;

namespace sub12 {

int freeTime(vector<pair<int,int>> &ap) {
    int maxrest = 0, rest = 0, start = 0, endt = 0;

    if(ap.empty()) {
        return e;
    }

    start = ap[0].first;
    endt = start + ap[0].second;
    maxrest = ap[0].first;

    for(int i = 1; i < ap.size(); i ++) {
        start = max(endt, ap[i].first);
        maxrest = max(maxrest, start - endt);
        endt = start + ap[i].second;
    }

    maxrest = max(maxrest, e - endt);

    return maxrest;
}

vector<pair<int,int>> setPoint(vector<pair<int,int>> &app, int x) {
    vector<pair<int,int>> created;
    for(int i = 0; i < n; i++) {
        if(x <= i && i <= x + k - 1) {
            continue;
        }
        created.push_back(app[i]);
    }
    return created;
}

void solve() {
    int res = 0;

    for(int i = 0; i < n; i++) {
        if(i + k - 1 < n) {
            vector<pair<int,int>> temp = setPoint(app, i);
            res = max(res, freeTime(temp));
        }
    }

    cout << res << "\n";
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("VIRUSS.INP", "r", stdin);
    freopen("VIRUSS.OUT", "w", stdout);

    int t;
    cin >> t;

    while(t--) {
        app.clear();

        cin >> n >> e >> k;

        for(int x,y,i = 0; i < n; i++) {
            cin >> x >> y;
            app.push_back({x,y});
        }

        sub12::solve();
    }
}
