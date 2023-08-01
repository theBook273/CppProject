#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        set<int> s;

        for (int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }

        int a[s.size()];

        int dem = 0;

        for (int i : s)
        {
            nums[dem++] = i;
        }

        return s.size();
    }
};