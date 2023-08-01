#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a[cost.size()] = {cost[0]};

        if (cost.size() == 1)
            return a[0];

        a[1] = cost[1];

        for (int i = 2; i < cost.size(); i++)
        {
            a[i] = min(cost[i] + a[i - 1], cost[i] + a[i - 2]);
        }

        return min(a[cost.size() - 1], a[cost.size() - 2]);
    }
};
