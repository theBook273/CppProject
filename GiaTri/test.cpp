#include<bits/stdc++.h>

using namespace std;

long long a,b,tong(0);
vector<long long >v;

bool check(long long n)
{
    for(long long i(2); pow(i,2) <= n; i++)
    {
        if(n % (long long)pow(i,2) == 0)
        {
            return 1;
        }
    }
    return 0;
}

long long main()
{


    cin >> a >> b;

    for(long long i(a); i <= b; i++)
    {
        for(long long j(i+1); j <= b; j++)
        {
            if(check(i * j))
            {
                tong ++;
            }
        }
    }

    cout << tong;
}
