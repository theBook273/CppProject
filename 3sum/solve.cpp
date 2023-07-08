#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    vector<int> nums;
    vector<vector<int>> res;
    unordered_map<int, int> mp;
    int dem = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
        mp[nums[i]]++;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n && nums[i] < 0; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = 0 - nums[i] - nums[j];
            if (mp.count(temp))
            {
                res[dem].push_back(nums[i]);
                res[dem].push_back(nums[j]);
                res[dem++].push_back(temp);
            }
        }
    }
}