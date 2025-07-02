#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n, tong = 0;
    cin >> n;

    long long a[] = {0, 1, 2, 4, 8, 16, 32};

    if (n <= 6)
    {
        cout << a[n];
    }
    else
    {
        for (long long i = 7; i <= n; i++)
        {
            for (long long j = 1; j <= 5; j++)
            {
                tong += a[j];
                a[j] = a[j + 1];
            }

            tong += a[6];
            a[5] = a[6];

            tong %= long long(1e9 + 7);
            a[6] = tong;

            tong = 0;
        }

        cout << a[6];
    }
}
