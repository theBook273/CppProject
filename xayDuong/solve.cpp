#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<long long, long long>, long long>> road[100000];

long long between[100000];

long long main()
{
    long long n, m;
    cin >> n >> m;

    for (long long i = 1; i <= m; i++)
    {
        long long u, v, distance;

        cin >> u >> v >> distance;

        road[u].push_back({{v, distance}, i});

        road[v].push_back({{u, distance}, i});
    }

    between[1] = 0;

    for (long long i = 2; i <= n; i++)
    {
        between[i] = 1e9;
    }

    queue<long long> nodeToVisit;

    nodeToVisit.push(1);

    while (!nodeToVisit.empty())
    {
        for ()
    }
}
