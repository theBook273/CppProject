#include <bits/stdc++.h>

using namespace std;

long long main()
{
    freopen("COST.INP", "r", stdin);
    freopen("COST.OUT", "w", stdout);

    long long n, a, b;

    cin >> n >> a >> b;

    long long box[10000000];

    for (long long i = 0; i < n; i++)
    {
        cin >> box[i];
    }

    long long tong = 0;

    for (long long i = 0; i < n; i++)
    {
        if (box[i] == 2)
            tong += (a + b);

        if (box[i] == 1)
            tong += min(a, b);
    }

    cout << tong;
}
