#include <bits/stdc++.h>

using namespace std;
long long n, k, dem = 0;
char temp[3] = {'L', 'Q', 'D'};
string s, res;

void create(long long k)
{
    for (long long i = 0; i < k; i++)
    {
        res += temp[0];
    }

    for (long long i = 0; i < k; i++)
    {
        res += temp[1];
    }

    for (long long i = 0; i < k; i++)
    {
        res += temp[2];
    }
}

long long main()
{
    cin >> n >> k >> s;

    cout << n - k * 3;
}
