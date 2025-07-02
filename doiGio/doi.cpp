#include <bits/stdc++.h>

using namespace std;

long long h, m, a, b;

long long doi(long long gioDoi)
{
    while (gioDoi < 0)
    {
        gioDoi = 24 + gioDoi;
    }
    while (gioDoi > 23)
    {
        gioDoi = gioDoi - 24;
    }

    return gioDoi;
}

long long main()
{
    cin >> h >> m >> a >> b;

    long long gioDoi = h - a;

    gioDoi = doi(gioDoi);

    gioDoi += b;

    gioDoi = doi(gioDoi);

    cout << gioDoi << " " << m;
}
