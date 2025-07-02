#include <bits/stdc++.h>

using namespace std;

long long mucTieu, soXu, soCach = 0;
vector<long long> xu;

void chon(long long tongXu)
{
    if (tongXu == mucTieu)
    {
        soCach++;
        return;
    }

    for (long long i = 0; i < soXu; i++)
    {
        if (tongXu + xu[i] <= mucTieu)
        {
            tongXu += xu[i];
            chon(tongXu);
            tongXu -= xu[i];
        }
    }
}

long long main()
{
    cin >> soXu >> mucTieu;

    for (long long i = 0; i < soXu; i++)
    {
        long long temp;
        cin >> temp;
        xu.push_back(temp);
    }

    chon(0);

    cout << soCach;
}
