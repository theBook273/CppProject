#include<bits/stdc++.h>

using namespace std;

bool a[2000000];
long long n;

long long main()
{
    memset(a,1,2000000);

    for(long long i = 2;i <= 1000012; i++)
    {
        if(a[i] == 1)
        {
            for(long long j = 2; j * i < 2000000; j++)
            {
                a[i*j] = 0;
            }
        }
    }

    cin >> n;

    for(long long i = n+1; i <= 2000000; i++)
    {
        if(a[i])
        {
            cout << i;
            break;
        }
    }
}
