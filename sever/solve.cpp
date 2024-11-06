#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, asc[10000000];
set<pair<int, int>> bridge;
set<int> tplt;
vector<pair<int, int>> res;

int ascCheck(int x) {
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

void join(int x, int y) {
    x = ascCheck(x);
    y = ascCheck(y);
    if (x == y) return;
    if (x < y) swap(x, y);
    asc[x] = y;
}

int checkLT() {
    tplt.clear();
    for (int i = 0; i < n; i++) {
        tplt.insert(asc[i]);
    }
    return tplt.size();
}

void input() {
    for (int i = 0; i < n; i++) {
        asc[i] = i;
    }
    for (int i = 0; i < n; i++) {
        int temp, s;
        char u, c;
        cin >> temp >> u >> s >> c;
        for (int j = 0; j < s; j++) {
            int a;
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
    vector<pair<int, int>> v;
    int root = checkLT();

    for (auto i : bridge) {
        v.push_back(i);
    }
    // int dem = 0;
    // for (auto i : v) {
    //     cout << i.first << " " << i.second << "\n";
    // }
    // // if (mark == 19) {
    // for (int i = 0; i < n; i++) {
    //     cout << asc[i] << " ";
    // }
    // cout << endl;

    for (int mark = 0; mark < v.size(); mark++) {
        for (int o = 0; o < n; o++) {
            asc[o] = o;
        }
        for (int i = 0; i < v.size(); i++) {
            if (i != mark) join(v[i].first, v[i].second);
        }
        // for (int t = 0; t < n; t++) {
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