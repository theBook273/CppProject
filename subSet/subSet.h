#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> temp;
    bool checked[1000];
    int tongMod;

public:
    void solve(int tong, int pos, vector<int> nums)
    {
        if (accumulate(temp.begin(), temp.end(), 0) == tong)
        {
            res.push_back(temp);
            return;
        }

        for (int i = pos; i < nums.size(); i++)
        {
            if (!checked[i] && tongMod + nums[i] <= tongMod)
            {
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        solve(target, 0, candidates);
    }
};