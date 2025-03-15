#include <bits/stdc++.h>

using namespace std;

int main() {
    int s1, s2, k, tong = 0;

    cin >> s1 >> s2 >> k;

    for (int i = s1; i <= s2; i++) {
        int temp = i;
        while (temp != 0) {
            if (temp % 10 == k) {
                tong++;
            }
            temp /= 10;
        }
    }

    cout << tong;
}