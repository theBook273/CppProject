#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, tong = 0;

    cin >> n;

    int limit = (n - 1) * 2 + 1;

    for (int i = 1; i <= limit; i += 2)
    {
        tong += i;
    }

    cout << tong;
}