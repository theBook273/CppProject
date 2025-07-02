#include <bits/stdc++.h>

using namespace std;

long long bat[1000000], tat[1000000], sang[10000000], somNhat = 0, treNhat = 0, sangNhat = 0, tong = 0;

long long main()
{
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> bat[i] >> tat[i];

        somNhat = min(somNhat, bat[i]);
        treNhat = max(treNhat, tat[i]);

        while (bat[i] <= tat[i])
        {
            sang[bat[i]]++;
            sang[tat[i]]++;
            bat[i]++;
            tat[i]--;
        }
    }

    for (long long i = somNhat; i <= treNhat; i++)
    {
        sangNhat = max(sangNhat, sang[i]);
    }

    for (long long i = somNhat; i <= treNhat; i++)
    {
        if (sang[i] == sangNhat)
        {
            tong++;
        }
    }

    cout << sangNhat << "\n"
         << tong;
}
