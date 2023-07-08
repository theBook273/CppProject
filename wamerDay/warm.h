#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> next(temperatures.size(), 0);
        next[temperatures.size() - 1] = 0;
        for (int i = temperatures.size() - 1; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (temperatures[j] < temperatures[i])
                {
                    next[j] = i - j;
                }
            }
        }

        return next;
    }
};