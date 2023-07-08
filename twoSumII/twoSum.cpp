#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, numbers[100000], target;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cin >> target;

    int l = 0;
    r = numbers.size() - 1;

    while (l < r)
    {
        if (numbers[r] + numbers[l] == target)
        {
            return {r + 1, l + 1};
        }
        if (numbers[r] >= target)
        {
            r--;
            continue;
        }
        if (numbers[l] < target)
        {
            l++;
        }
    }

    return {};
}