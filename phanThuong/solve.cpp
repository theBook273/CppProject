#include <bits/stdc++.h>

using namespace std;

long long gift[100000];

long long nums, valueG[1000000];

long long solve(long long n)
{
    if (n < 0)
        return 0;

    if (valueG[n] != -1)
        return valueG[n];

    if (n >= 1)
        valueG[n] = max(max(solve(n - 2) + gift[n], gift[n - 1] + gift[n] + solve(n - 3)), solve(n - 1));
    else
        valueG[n] = max(solve(n - 2) + gift[n], solve(n - 1));

    return valueG[n];
}

long long32_t main()
{

    cin >> nums;

    for (long long i = 0; i < nums; i++)
    {
        cin >> gift[i];
        valueG[i] = -1;
    }

    cout << solve(nums - 1);
}
