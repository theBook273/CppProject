#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        string a, b;
        cin >> a >> b;
        int ans = a.size() + b.size();
        for (int i = 0; i < b.size(); i++) {
            int dem = i;
            for (auto c : a) {
                if (dem < b.size() && c == b[dem]) ++dem;
            }
            ans = min(ans, int(a.size() + b.size() - (dem - i)));
        }
        cout << ans << "\n";
    }
}