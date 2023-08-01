#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> road[100000];

int between[100000];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int u, v, distance;

        cin >> u >> v >> distance;

        road[u].push_back({{v, distance}, i});

        road[v].push_back({{u, distance}, i});
    }

    between[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        between[i] = 1e9;
    }

    queue<int> nodeToVisit;

    nodeToVisit.push(1);

    while (!nodeToVisit.empty())
    {
        for ()
    }
}