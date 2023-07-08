#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, nums[100000];

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    map<int, int> oM;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> res;

    for (int i = 0; i < n; i++)
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