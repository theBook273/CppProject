#include<bits/stdc++.h>

using namespace std;

long long n, a[10000000], maxN = -1, pos;

vector<long long> so, soluong;

long long main()
{

    cin >> n;

    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for(long long i = 0; i < n; i++)
    {
        long long temp = 0, tempForJ;
        for(long long j = i + 1; j < n; j++)
        {
            temp++;
            if(a[i] != a[j])
            {
                if(a[i] != a[j + 1])
                break;
                continue;
            }
        }
        if(temp > maxN)
        {
            maxN = temp;
            pos = i;
        }
    }
    cout << maxN;
}
