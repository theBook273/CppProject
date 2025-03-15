#include <bits/stdc++.h>
#include "subSet.h"

using namespace std;

int main()
{
    Solution a;

    vector<int> n = {1, 2, 3};

    vector<vector<int>> res = a.combinationSum(n);

    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}