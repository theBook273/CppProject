#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 6;

#define long long long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)

typedef pair<long long, long long> PII;
typedef map<long long, long long> Map;

long long n, x, y;

void solve() {
    cin >> n >> x >> y;
    long long sum = 0;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) cin >> a[i], sum += a[i];

    sort(a.begin(), a.end());

    long long res = 0;
    long long u = sum - y, v = sum - x;
    // cout<<u<<' '<<v<<endl;
    // cout<<n<<endl;
    for (long long i = 0; i + 1 < n; i++) {
        long long l = i + 1, r = n - 1;
        while (l < r) {
            long long mid = l + r >> 1;
            if (a[mid] >= u - a[i])
                r = mid;
            else
                l = mid + 1;
        }
        if (a[l] < u - a[i]) continue;
        long long ok1 = l;

        l = i + 1, r = n - 1;
        while (l < r) {
            long long mid = l + r + 1 >> 1;
            if (a[mid] <= v - a[i])
                l = mid;
            else
                r = mid - 1;
        }
        if (a[l] > v - a[i]) continue;
        long long ok2 = l;
        res += ok2 - ok1 + 1;
        // cout<<i<<' '<<ok1<<' '<<ok2<<endl;
    }

    cout << res << endl;
}
signed main() {
    IOS;
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
}
