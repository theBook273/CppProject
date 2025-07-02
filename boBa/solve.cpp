#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long a, b, z, y, m, n, tong = 0;

    cin >> a >> b >> z >> y >> m >> n;

    for (long long i = a; i <= b; i++)
    {
        for (long long j = z; j <= y; j++)
        {
            long long temp = i * j;

            if (m <= temp && temp <= n)
            {
                tong++;
            }
        }
    }

    cout << tong;
}
