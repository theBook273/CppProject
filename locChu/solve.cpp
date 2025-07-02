#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n, tong = 0;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        char temp;

        cin >> temp;

        if (temp == 'V' || temp == 'I' || temp == 'P')
        {
            tong++;
        }
    }

    cout << tong / 3;
}
