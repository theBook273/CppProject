#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 2 * 1e5 + 27;

char a[maxn];

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, l1 = 0, c = 0;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == '_')
                c++;
            else
                l1++;
        }
        if (l1 < 2 || n < 3 || c == 0)
            cout << "0\n";
        else
            cout << (int)(floor(l1 / 2.0) * ceil(l1 / 2.0) * c) << endl;
    }
}