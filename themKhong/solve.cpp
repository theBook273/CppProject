#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n, k;

    deque<long long> q;

    cin >> n >> k;

    for (long long i = 0; i < n; i++)
    {
        long long temp;

        cin >> temp;

        q.push_back(temp);
    }

    while (k--)
    {
        q.pop_front();
        q.push_back(0);
    }

    for (long long i : q)
    {
        cout << i << " ";
    }
}
