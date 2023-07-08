#include <bits/stdc++.h>

using namespace std;

long long h, m, a, b;

int doi(int gioDoi)
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

int main()
{
    cin >> h >> m >> a >> b;

    int gioDoi = h - a;

    gioDoi = doi(gioDoi);

    gioDoi += b;

    gioDoi = doi(gioDoi);

    cout << gioDoi << " " << m;
}