#include <bits/stdc++.h>

using namespace std;

vector<long long> nums;

long long main()
{
    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;
        nums.push_back(a);
    }

    set<long long> s;

    for (long long i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    return (s.size() != n);
}
