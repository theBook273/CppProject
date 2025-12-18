#include <bits/stdc++.h>
#define int long long

using namespace std;

int n;
vector<pair<int,int>> knot;

namespace sub1 {

vector<int> enlighted;

bool check(int mark) {
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        if((mark >> i) & 1) {
            pos.push_back(i);
        }
    }

    for(auto x : pos) {
        enlighted[x]++;
        for(int i = 0; i < n; i++) {
            if(x != i && (knot[i].first == knot[x].first || knot[i].second == knot[x].second)) {
                enlighted[i]++;
            }
        }
    }

    bool dem = 1;

    for(int i = 0; i < n; i++) {
        if(enlighted[i] > 2) {
            return 0;
        }
        dem = dem && enlighted[i];
    }

    return dem;
}

string bin(int mark) {
    string s;
    for(int i = n - 1; i >= 0; i--) {
        char ins = '0';
        if((mark >> i) & 1) {
            ins = '1';
        }
        s.push_back(ins);
    }
    return s;
}

signed solve() {
    int full = (1 << n);

    for(int mark = 1; mark < full; mark++) {
        enlighted.assign(n, 0);
        if(check(mark)) {
            cout << bin(mark);
            return 0;
        }
    }

    return 0;
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("SLAMP.INP", "r", stdin);
    freopen("SLAMP.OUT", "w", stdout);

    cin >> n;
    for(int x,y, i = 0; i < n; i++) {
        cin >> x >> y;
        knot.push_back({x,y});
    }

    if(n <= 16) {
        return sub1::solve();
    }

    return 0;
}
