#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, s, r;
vector<int> y;
deque<int> x;
vector<string> filter;

namespace sub1 {

void roll(int cnt) {
    for(int i = 0; i <= cnt; i++) {
        int temp = x.front();
        x.pop_front();
        x.push_back(temp);
    }
}

void protocol() {
    roll(s);

    for(auto i : x) {
        cout << i << " ";
    }
    cout << "\n";
    for(auto i : y) {
        cout << i << " ";
    }
    cout << "\n";

    for(auto fil : filter) {
        for(int i = 0; i < n; i++) {
            if(fil == "and") {
                y[i] = y[i] & x[i];
            } else if(fil == "or") {
                y[i] = y[i] | x[i];
            } else {
                y[i] = y[i] ^ x[i];
            }
        }
        for(auto i : y) {
            cout << i << " ";
        }
        cout << "\n";
    }


    cout << "\n";
}

signed solve() {
    for(int i = 1; i <= r; i++) {
        protocol();
    }

    for(auto i : y) {
        cout << i << " ";
    }

    return 0;
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ANDORXOR.INP", "r", stdin);
    freopen("ANDORXOR.OUT", "w", stdout);

    cin >> n >> m >> s >> r;

    for(int a,i = 0; i < n; i++) {
        cin >> a;
        x.push_back(a);
        y.push_back(a);
    }

    string _;
    for(int i = 0; i < m; i++) {
        cin >> _;
        filter.push_back(_);
    }

    if(n <= 1000 && r <= 100) {
        return sub1::solve();
    }

    return 0;
}
