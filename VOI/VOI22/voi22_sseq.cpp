#include<bits/stdc++.h>

using namespace std;

struct Point {
    int type, state, val;
    const bool operator<(const Point& other) {
        return type < other.type;
    }
};

int n, res(0);
vector<Point> point;
unordered_map<int,bool> marking;

namespace sub12 {

signed solve() {
    unordered_set<int> se;
    for(int i(0); i < (int)point.size(); ++i) {
        se.clear();
        int sum(0);
        if(marking[point[i].type]) {
            for(int j(i); j < (int)point.size(); ++j) {
                if(se.empty() || se.find(point[j].state) == se.end()) {
                    se.insert(point[j].state);
                    continue;
                }
                if(se.find(point[j].state) != se.end()) {
                    sum += point[j].val;
                    if(marking[point[j].type]) {
                        res = max(res, sum);
                    }
                    se.erase(point[j].state);
                }
            }
        }

    }

    cout << res << "\n";
    return 0;
}

}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("SSEQ.INP", "r", stdin);
    freopen("SSEQ.OUT", "w", stdout);

    cin >> n;
    for(int l,r,x, i(0); i < n; ++i) {
        cin >> l >> r >> x;
        point.push_back({l, i, x});
        point.push_back({r, i, x});

        marking[l] = marking[l] || (x > 0);
        marking[r] = marking[r] || (x > 0);
    }

    sort(point.begin(), point.end());

    return sub12::solve();
}
