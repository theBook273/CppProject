#include <bits/stdc++.h>

using namespace std;

bool prime[100000000];
long long tong = 0;
vector<long long> primeNum;
long long r, l;

long long main()
{

    cin >> l >> r;

    memset(prime, 1, r + 1);

    for (long long i = 2; i <= r; i++)
    {
        if (prime[i])
        {
            primeNum.push_back(i);
            for (long long j = 2; j * i <= r; j++)
            {
                prime[i * j] = 0;
            }
        }
    }

    for (long long i = 0; i < primeNum.size(); i++)
    {
        if (l <= pow(primeNum[i], 3) && pow(primeNum[i], 3) <= r)
        {
            tong++;
        }
        for (long long j = i + 1; primeNum[j] * primeNum[i] <= r && j < primeNum.size(); j++)
        {
            if (primeNum[i] * primeNum[j] >= l)
            {
                tong++;
            }
        }
    }
    cout << tong;
}
