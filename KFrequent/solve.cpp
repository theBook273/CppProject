#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n, k, nums[100000];

    cin >> n >> k;

    for (long long i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    map<long long, long long> oM;
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
    vector<long long> res;

    for (long long i = 0; i < n; i++)
    {
        oM[nums[i]]++;
    }

    for (auto i : oM)
    {
        q.push({i.second, i.first});
        if (q.size() > k)
        {
            q.pop();
        }
    }

    while (!q.empty())
    {
        res.push_back(q.top().second);
        q.pop();
    }
}
