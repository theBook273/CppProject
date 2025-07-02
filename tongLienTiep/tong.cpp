#include <bits/stdc++.h>

using namespace std;

long long n, s,
    a[1000000], b[1000000];

long long main()
{
    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cin >> s;

    b[0] = a[0];

    for (long long i = 1; i < n; i++)
    {
        b[i] = b[i - 1] + a[i];
    }

    for (long long i = 0; i < n; i++)
    {
        if (b[i] == s)
        {
            for (long long j = 0; j <= i; j++)
            {
                cout << a[j] << " ";
            }
            return 0;
        }
        if (b[i] >= s)
        {
            for (long long j = 0; j <= i; j++)
            {
                if (b[i] - b[j] == s)
                {
                    for (long long k = j + 1; k <= i; k++)
                    {
                        cout << a[k] << " ";
                    }
                    return 0;
                }
            }
        }
    }

    cout << -1;
}
