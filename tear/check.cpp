#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        n -= ceil(n / 2.0);
        cout << n << endl;
    }
}