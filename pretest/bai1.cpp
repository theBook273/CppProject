#include <bits/stdc++.h>
#define int long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (abs(a - b) % 2 == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}