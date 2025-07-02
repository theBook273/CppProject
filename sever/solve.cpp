#include <bits/stdc++.h>
#define long long long long

using namespace std;

long long n, asc[10000000];
set<pair<long long, long long>> bridge;
set<long long> tplt;
vector<pair<long long, long long>> res;

long long ascCheck(long long x) {
    if (asc[x] == x) return x;
    return asc[x] = ascCheck(asc[x]);
    // return ascCheck(asc[x]);
}

void initN() {
    bridge.clear();
    tplt.clear();
    res.clear();
    memset(asc, 0, sizeof(asc));
}

void join(long long x, long long y) {
    x = ascCheck(x);
    y = ascCheck(y);
    if (x == y) return;
    if (x < y) swap(x, y);
    asc[x] = y;
}

long long checkLT() {
    tplt.clear();
    for (long long i = 0; i < n; i++) {
        tplt.insert(asc[i]);
    }
    return tplt.size();
}

void input() {
    for (long long i = 0; i < n; i++) {
        asc[i] = i;
    }
    for (long long i = 0; i < n; i++) {
        long long temp, s;
        char u, c;
        cin >> temp >> u >> s >> c;
        for (long long j = 0; j < s; j++) {
            long long a;
            cin >> a;
            join(a, temp);
            if (temp > a)
                bridge.insert({a, temp});
            else
                bridge.insert({temp, a});
        }
    }
}

void solve() {
    vector<pair<long long, long long>> v;
    long long root = checkLT();

    for (auto i : bridge) {
        v.push_back(i);
    }
    // long long dem = 0;
    // for (auto i : v) {
    //     cout << i.first << " " << i.second << "\n";
    // }
    // // if (mark == 19) {
    // for (long long i = 0; i < n; i++) {
    //     cout << asc[i] << " ";
    // }
    // cout << endl;

    for (long long mark = 0; mark < v.size(); mark++) {
        for (long long o = 0; o < n; o++) {
            asc[o] = o;
        }
        for (long long i = 0; i < v.size(); i++) {
            if (i != mark) join(v[i].first, v[i].second);
        }
        // for (long long t = 0; t < n; t++) {
        //     cout << asc[t] << " ";
        // }
        // cout << endl;
        if (checkLT() != root) {
            res.push_back({v[mark].first, v[mark].second});
        }
    }
    if (res.size() == 1)
        cout << res.size() << " critical link" << endl;
    else
        cout << res.size() << " critical links" << endl;
    for (auto i : res) {
        cout << i.first << " - " << i.second << endl;
    }
    cout << endl;
}

signed main() {
    while (cin >> n) {
        initN();
        input();
        solve();
    }
}
