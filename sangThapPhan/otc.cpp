#include <bits/stdc++.h>

using namespace std;

long long toBin(string s)
{
    long long tong = 0;
    for (long long i = 0; i < s.size(); i++)
    {
        tong += ((s[i] - '0') * pow(2, s.size() - i - 1));
    }

    return tong;
}

long long main()
{
    long long tong = 0;
    string s1, s2;

    cin >> s1 >> s2;

    for (long long i = toBin(s1); i <= toBin(s2); i++)
    {
        long long n = sqrt(i);
        if (pow(n, 2) == i)
        {
            tong++;
        }
    }

    cout << tong;
}
