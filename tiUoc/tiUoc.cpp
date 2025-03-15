#include <bits/stdc++.h>

using namespace std;

long long n;

bool prime[1000000];

double tongUoc(int n)
{
    double tong = n + 1;

    for (int i = sqrt(n); i > 1; i--)
    {
        if (n % i == 0)
        {
            tong += i + n / i;
        }
    }

    return tong;
}

int main()
{
    memset(prime, 1, 1000000);

    for (int i = 2; i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = 2; j * i <= 100000; j++)
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