#include <bits/stdc++.h>

using namespace std;

int bat[1000000], tat[1000000], sang[10000000], somNhat = 0, treNhat = 0, sangNhat = 0, tong = 0;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
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

    for (int i = somNhat; i <= treNhat; i++)
    {
        sangNhat = max(sangNhat, sang[i]);
    }

    for (int i = somNhat; i <= treNhat; i++)
    {
        if (sang[i] == sangNhat)
        {
            tong++;
        }
    }

    cout << sangNhat << "\n"
         << tong;
}