#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> prices;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }

    int buy = INT_MAX,
        maxN = 0;

    for (int i = 0; i < n; i++)
    {
        buy = min(buy, prices[i]);
        maxN = max(maxN, prices[i] - buy);
    }

    return maxN;
}