#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, a[200009], x;
map<int, int> mp;

main() {
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (mp.count(a[i])) {
            if (a[i] * 2 == x) {
                cout << mp[a[i]] << " " << i;
                return 0;
            }
        }
        mp[a[i]] = i;
    }

    for (auto i : mp) {
        if (mp.count(x - i.first) && i.second != mp[x - i.first]) {
            cout << i.second << " " << mp[x - i.first];
            return 0;
        }
    }

    cout << "IMPOSSIBLE";
}
