#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

namespace sub1 {

signed solve() {
    vector<int> model = a;
    sort(model.begin(), model.end());

    int res = 0;

    for (int i = 0; i < n; i++) {
        int best = 0;
        if(a[i] != 0) {
            for (int j = 0; j < n; j++) {
                if (a[i] == model[j]) {
                    int x = 0;
                    while (max(i + x, j + x) < n && a[i + x] == model[j + x]) {
                        x++;
                        if(best < x){
                            best = x;
                        }
                    }
                }
            }
        }
        if(best != 0) {
            for(int j = 0; j < best; j++) {
                a[i + j] = 0;
            }
            res -=- 1;
        }
    }

    cout << res;

    return 0;
}

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("SORT.INP", "r", stdin);
    freopen("SORT.OUT", "w", stdout);

    cin >> n;
    for (int x, i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    return sub1::solve();
}
