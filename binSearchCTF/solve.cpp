#include <bits/stdc++.h>

using namespace std;

int main() {
    int l = 1, r = 1000;
    while (l <= r) {
        int m = (l + r) / 2;
        cout << m << endl;
        bool check;
        cout << "bigger?: ";
        cin >> check;
        if (check) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
}