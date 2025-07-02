#include <bits/stdc++.h>

using namespace std;
long long a[1000000], n;
unordered_map<string, long long> dem;
vector<long long> nev;

long long main()
{
    long k = 0;
    freopen("FINDDANTE.INP", "r", stdin);
    freopen("FINDDANTE.OUT", "w", stdout);
    while (cin >> n)
    {
        if (n < 0)
        {
            nev.push_back(n);
        }
        a[k] = abs(n);
        k++;
    }

    for (long long i = 0; i < k; i++)
    {
        dem[to_string(a[i])]++;
    }

    for (long long i = 0; i < k; i++)
    {
        if (dem[to_string(a[i])] % 2 != 0)
        {
            for (long long j : nev)
            {
                if (-a[i] == j)
                {
                    cout << -a[i];
                    return 0;
                }
            }
            cout << a[i];
            return 0;
        }
    }
}
