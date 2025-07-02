#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long tong = 0;

    for (long long i = 0; i < 6; i++)
    {
        long long temp;

        cin >> temp;

        (temp % 2 == 0) ? tong += (temp / 2) : tong += ((temp / 2) + 1);
    }

    cout << tong << " " << tong * 900000;
}
