#include <bits/stdc++.h>
#define int long long

using namespace std;

main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];

        map<int, int> mp;

        for (auto &i : a) {
            cin >> i;
            mp[i]++;
        }

        int j = 1;

        set<int> s;

        for (int i = 0; i < n; i++) {
            int temp = s.size();
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