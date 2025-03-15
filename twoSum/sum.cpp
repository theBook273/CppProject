#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main()
{
    int n, s;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    cin >> s;

    unordered_map<int, int> numMap;

    for (int i = 0; i < n; i++)
    {
        numMap[nums[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        int res = s - nums[i];
        if (numMap.count(res) && numMap[res] != i)
        {
            cout << i << " " << numMap[res];
            return 0;
        }
    }
}