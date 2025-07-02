#include<bits/stdc++.h>

using namespace std;

bool check[1000000000];
long long a,b,tong = 0;

long long main()
{


    cin >> a >> b;

    for(long long i = 2; pow(i,2) <= b * 10; i++)
    {
        long long temp = pow(i,2);
        for(long long j = 2; j * i <= b * 10; j++)
        {
            check[temp*j] = 1;
        }
    }

    for(long long i = a; i <= b; i++)
    {
        for(long long j = i + 1; j <= b; j++)
        {
            if(check[i*j])
            {
                tong++;
            }
        }
    }

    cout << tong;
}
