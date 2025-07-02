#include<bits/stdc++.h>

using namespace std;

bool passed = 0;

long long main()
{
    long long n;

    cin >> n;

    long long t = n;

    while(!passed)
    {
        passed = 1;
        for(long long i = 1; i <= n; i++)
        {
            if(t % i != 0)
            {
                passed = 0;
                break;
            }
        }
        t++;
    }

    cout << ((t - 1) % long long(1e9+7));
}
