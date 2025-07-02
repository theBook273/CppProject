#include <bits/stdc++.h>
#define long long long long

using namespace std;

main() {
    cin.tie(0)->sync_with_stdio(0);

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n], b[n];

        map<long long, long long> mp;

        for (auto &i : a) {
            cin >> i;
            mp[i]++;
        }

        long long j = 1;

        set<long long> s;

        for (long long i = 0; i < n; i++) {
            long long temp = s.size();
            s.insert(a[i]);
            if (s.size() != temp)
                b[i] = a[i];
            else {
                for (; j <= n; j++) {
                    if (mp[j] == 0) {
                        mp[j]++;
                        b[i] = j;
                        break;
                    }
                }
            }
        }

        for (auto i : b) cout << i << " ";
        cout << endl;
    }
}
