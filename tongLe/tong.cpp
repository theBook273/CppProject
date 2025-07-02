#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n, tong = 0;

    cin >> n;

    long long limit = (n - 1) * 2 + 1;

    for (long long i = 1; i <= limit; i += 2)
    {
        tong += i;
    }

    cout << tong;
}
