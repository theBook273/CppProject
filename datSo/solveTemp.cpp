#include <bits/stdc++.h>

using namespace std;
using ll = long long;

signed main() {
    cin.tie(NULL)->sync_with_stdio(NULL);
    int n;
    char a;
    string s;
    cin >> n >> a >> s;

    n = s.size();

    s += a;
    string maxS = "";

    for (int i = s.size() - 1; i > 0; i--) {
        maxS = max(s, maxS);
        swap(s[i], s[i - 1]);
    }
    maxS = max(s, maxS);
    cout << maxS;
}