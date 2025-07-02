#include <bits/stdc++.h>

using namespace std;

vector<long long> nums;

long long main()
{
    long long n, s;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        nums.push_back(a);
    }

    cin >> s;

    unordered_map<long long, long long> numMap;

    for (long long i = 0; i < n; i++)
    {
        numMap[nums[i]] = i;
    }

    for (long long i = 0; i < n; i++)
    {
        long long res = s - nums[i];
        if (numMap.count(res) && numMap[res] != i)
        {
            cout << i << " " << numMap[res];
            return 0;
        }
    }
}
