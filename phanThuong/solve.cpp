#include <bits/stdc++.h>

using namespace std;

int gift[100000];

int nums, valueG[1000000];

int solve(int n)
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

int32_t main()
{

    cin >> nums;

    for (long long i = 0; i < nums; i++)
    {
        cin >> gift[i];
        valueG[i] = -1;
    }

    cout << solve(nums - 1);
}