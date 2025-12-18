#include<bits/stdc++.h>
#define int long long

using namespace std;

int m,k;
string model;
vector<string> cand;

namespace sub1 {

string balance(string &a, string &b) {
    string res = b;
    while(res.size() < a.size()) {
        res += b;
    }

    while(res.size() > a.size()) {
        res.pop_back();
    }
    return res;
}

int diff(string &a, string b) {
    int dem = 0;
    for(int i = 0; i < a.size(); i++) {
        dem += (a[i] != b[i]);
    }
    return dem;
}

signed solve() {
    for(int i = 0; i < m; i++) {
        cout << diff(model, balance(model, cand[i])) << "\n";
    }
    return 0;
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ZIP.INP", "r", stdin);
    freopen("ZIP.OUT", "w", stdout);

    cin >> m >> k;

    cin >> model;
    string _;
    for(int i = 0; i < m; i++) {
        cin >> _;
        cand.push_back(_);
    }
    return sub1::solve();
}
