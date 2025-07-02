#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n;
    vector<long long> prices;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long temp;
        cin >> temp;
        prices.push_back(temp);
    }

    long long buy = INT_MAX,
        maxN = 0;

    for (long long i = 0; i < n; i++)
    {
        buy = min(buy, prices[i]);
        maxN = max(maxN, prices[i] - buy);
    }

    return maxN;
}
