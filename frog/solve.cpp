#include <bits/stdc++.h>

using namespace std;

long long h[100001];
long long jump[100001];

long long main()
{
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    jump[0] = 0;
    jump[1] = abs(h[0] - h[1]);

    for (long long i = 2; i < n; i++)
    {
        long long temp1 = abs(h[i - 2] - h[i]);
        long long temp2 = abs(h[i - 1] - h[i]);

        jump[i] = min(jump[i - 2] + temp1, jump[i - 1] + temp2);
    }

    cout << jump[n - 1];
}
