#include <bits/stdc++.h>

using namespace std;

const double pi = 3.14159265;

long long main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    while (n--)
    {
        double r, l;

        cin >> l >> r;

        cout << fixed << setprecision(3) << (pi * r * r) * l / 360 << endl;
    }
}
