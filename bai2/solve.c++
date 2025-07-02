#include <bits/stdc++.h>
#define int long long

using namespace std;

const int pre[] = {0,    1,    2,    4,     8,     16,    23,    46,    29,
                   58,   116,  223,  446,   289,   578,   1156,  1223,  2446,
                   2489, 4789, 5789, 11578, 12356, 12247, 24449, 48889, 77789};

const int sam[] = {155578, 111356, 122227, 244445, 48889, 77789};

signed main() {
    int n;
    cin >> n;
    if (n <= 26)
        cout << pre[n];
    else {
        n -= 27;
        n %= 6;
        cout << sam[n];
    }
}