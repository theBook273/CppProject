#include <bits/stdc++.h>

using namespace std;

long long so, n;

bool tamgiac[100000000];

long long main()
{
    for (long long i = 1; i * (i + 1) / 2 <= 10000000; i++)
    {
        tamgiac[i * (i + 1) / 2] = 1;
    }

    cin >> n;

    while (n--)
    {
        cin >> so;

        cout << tamgiac[so] << "\n";
    }
}
