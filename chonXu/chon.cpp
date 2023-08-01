#include <bits/stdc++.h>

using namespace std;

int mucTieu, soXu, soCach = 0;
vector<int> xu;

void chon(int tongXu)
{
    if (tongXu == mucTieu)
    {
        soCach++;
        return;
    }

    for (int i = 0; i < soXu; i++)
    {
        if (tongXu + xu[i] <= mucTieu)
        {
            tongXu += xu[i];
            chon(tongXu);
            tongXu -= xu[i];
        }
    }
}

int main()
{
    cin >> soXu >> mucTieu;

    for (int i = 0; i < soXu; i++)
    {
        int temp;
        cin >> temp;
        xu.push_back(temp);
    }

    chon(0);

    cout << soCach;
}