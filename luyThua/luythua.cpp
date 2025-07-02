#include <bits/stdc++.h>

using namespace std;

double tong = 0;

long long main()
{
    long long n;

    cin >> n;

    while (n--)
    {
        long long a;

        cin >> a;

        long long temp1 = a / 10,
            temp2 = a % 10;

        tong += pow(temp1, temp2);
    }

    cout << (long long)tong;
}
