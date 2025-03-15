#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[10000];
map<int, int> dem;

long long maxN = 0, pos = 0;

int main()
{
    // freopen("CHENH LECH.INP", "r", stdin);
    // freopen("CHENH LECH.OUT", "w", stdout);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x, y;

        cin >> x >> y;

        a[i] = {x, y};
    }

    for (int i = 0; i < n; i++)
    {
        dem[abs(a[i].first - a[i].second)]++;
    }

    for (int i = 0; i < n; i++)
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

    for (int i = 0; i < n; i++)
    {
        if (dem[abs(a[i].first - a[i].second)] == maxN && abs(a[i].first - a[i].second) == pos)
        {
            cout << a[i].first << " " << a[i].second << "\n";
        }
    }
}