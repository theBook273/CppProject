#include<bits/stdc++.h>

using namespace std;

bool passed = 0;

int main()
{
    int n;

    cin >> n;

    long long t = n;

    while(!passed)
    {
        passed = 1;
        for(int i = 1; i <= n; i++)
        {
            if(t % i != 0)
            {
                passed = 0;
                break;
            }
        }
        t++;
    }

    cout << ((t - 1) % int(1e9+7));
}
