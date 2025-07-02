#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long t;

    cin >> t;

    while (t--)
    {
        long long n;
        pair<long long, long long> maxOfThem = {0, 0};

        cin >> n;

        for (long long i = 1; i <= n; i++)
        {
            long long w, q;

            cin >> w >> q;

            if (w <= 10 && q > maxOfThem.second)
            {
                maxOfThem = {i, q};
            }
        }

        cout << maxOfThem.first << "\n";
    }
}
