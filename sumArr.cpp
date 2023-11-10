#include <bits/stdc++.h>

using namespace std;

int a[10000000];

int main() {
    int n, m;
    cin >> n >> m;

    map<int, int> mp;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        mp[a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (mp.count(m - a[i])) {
            if (m - a[i] == a[i] && mp[a[i]] < 2) {
                cout << "NO";
                return 0;
            }
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}