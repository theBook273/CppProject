#include <bits/stdc++.h>

using namespace std;

long long n;

bool prime[1000000];

double tongUoc(long long n)
{
    double tong = n + 1;

    for (long long i = sqrt(n); i > 1; i--)
    {
        if (n % i == 0)
        {
            tong += i + n / i;
        }
    }

    return tong;
}

long long main()
{
    memset(prime, 1, 1000000);

    for (long long i = 2; i <= 100000; i++)
    {
        if (prime[i])
        {
            for (long long j = 2; j * i <= 100000; j++)
            {
                prime[i * j] = 0;
            }
        }
    }

    cin >> n;

    long long temp = n;

    long long Utemp = tongUoc(n);

    while (n <= 1e5)
    {
        n++;
        if (!prime[n])
            if (n * Utemp == temp * tongUoc(n))
            {
                cout << n;
                return 0;
            }
    }
}
