#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sumM = nums[i] + nums[j] + nums[k];
                if (sumM == 0)
                {
                    result.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (sumM < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        vector<vector<int>> res;

        for (auto i : result)
        {
            res.push_back(i);
        }

        return res;
    }
};