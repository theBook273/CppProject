#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> a[10000];
map<long long, long long> dem;

long long maxN = 0, pos = 0;

long long main()
{
    // freopen("CHENH LECH.INP", "r", stdin);
    // freopen("CHENH LECH.OUT", "w", stdout);

    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long x, y;

        cin >> x >> y;

        a[i] = {x, y};
    }

    for (long long i = 0; i < n; i++)
    {
        dem[abs(a[i].first - a[i].second)]++;
    }

    for (long long i = 0; i < n; i++)
    {
        if (dem[abs(a[i].first - a[i].second)] > maxN)
        {
            maxN = dem[abs(a[i].first - a[i].second)];
            pos = abs(a[i].first - a[i].second);
        }
        else if (dem[abs(a[i].first - a[i].second)] == maxN)
        {
            if (abs(a[i].first - a[i].second) < pos)
            {
                pos = abs(a[i].first - a[i].second);
                maxN = dem[abs(a[i].first - a[i].second)];
            }
        }
    }

    cout << pos << "\n";

    for (long long i = 0; i < n; i++)
    {
        if (dem[abs(a[i].first - a[i].second)] == maxN && abs(a[i].first - a[i].second) == pos)
        {
            cout << a[i].first << " " << a[i].second << "\n";
        }
    }
}
