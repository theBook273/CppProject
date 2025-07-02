#include <bits/stdc++.h>
#define long long long long

using namespace std;

signed main() {
    long long t;
    cin >> t;
    while (t--) {
        string s;
        bool check = 0;
        cin >> s;
        string temp = s;

        for (long long i = s.size() - 2; i >= 0; i--) {
            for (long long j = s.size() - 1; j >= i; j--) {
                if (s[j] > s[i]) {
                    check = 1;
                    swap(s[i], s[j]);
                    sort(s.begin() + i + 1, s.end());
                    break;
                }
            }
            if (check) break;
        }
        if (check)
            cout << s;
        else
            cout << "no answer";
        cout << endl;
    }
}
