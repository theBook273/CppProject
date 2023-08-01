#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int a[10000];

        a[0] = nums[0];

        if (nums.size() == 1)
            return a[0];

        a[1] = max(nums[1], nums[0]);

        for (int i = 2; i < nums.size(); i++)
        {
            a[i] = max(a[i - 1], nums[i] + a[i - 2]);
        }

        return a[nums.size() - 1];
    }
};