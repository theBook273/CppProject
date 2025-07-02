#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n;
    cin >> n;

    while (n--)
    {
        long long a[3];

        for (long long i = 0; i < 3; i++)
        {
            cin >> a[i];
        }

        sort(a, a + 3);
        reverse(a, a + 3);

        if (a[0] + a[1] >= 10)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}
