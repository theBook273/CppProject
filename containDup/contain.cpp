#include <bits/stdc++.h>

using namespace std;

vector<int> nums;

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        s.insert(nums[i]);
    }

    return (s.size() != n);
}