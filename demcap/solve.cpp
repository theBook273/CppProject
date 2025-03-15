#include <bits/stdc++.h>
#define int long long

using namespace std;

const int maxn = 5 * 1e5 + 8;

int a[maxn], mark[maxn];
int n;

main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        int maxnow = 0;
        for (int j = i + 1; j < n; j++) {
            if (i + 1 == j) {
                res++;
            } else {
                maxnow = max(maxnow, a[j - 1]);
                if (a[i] < maxnow || a[j] < maxnow) {
                    break;
                } else
                    res++;
            }
        }
    }
    cout << res << endl;
}