#include <bits/stdc++.h>
#define int long long

using namespace std;
int n, a[100000];

signed main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int sig = 1;
        string out[2] = {"NO", "YES"};

        for (int i = 0; i < n - 1; i++) {
            int temp = abs(a[i + 1] - a[i]);
            if (temp != 5 && temp != 7) {
                sig = 0;
            }
        }

        cout << out[sig] << endl;
    }
}