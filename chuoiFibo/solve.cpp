#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s[93];
    s[1] = "A";
    s[2] = "B";

    for (int i = 3; i <= 10; i++) {
        s[i] = s[i - 2] + s[i - 1];
        cout << s[i] << "\n";
    }

    cout << "hello";
}