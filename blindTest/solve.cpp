#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 6;

#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)

typedef pair<int, int> PII;
typedef map<int, int> Map;

int n, x, y;

void solve() {
    cin >> n >> x >> y;
    int sum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];

    sort(a.begin(), a.end());

    int res = 0;
    int u = sum - y, v = sum - x;
    // cout<<u<<' '<<v<<endl;
    // cout<<n<<endl;
    for (int i = 0; i + 1 < n; i++) {
        int l = i + 1, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (a[mid] >= u - a[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] < u - a[i]) continue;
        int ok1 = l;

        l = i + 1, r = n - 1;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (a[mid] <= v - a[i])
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] > v - a[i]) continue;
        int ok2 = l;
        res += ok2 - ok1 + 1;
        // cout<<i<<' '<<ok1<<' '<<ok2<<endl;
    }

    cout << res << endl;
}
signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}