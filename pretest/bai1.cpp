#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    long long t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        if (abs(a - b) % 2 == 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}
