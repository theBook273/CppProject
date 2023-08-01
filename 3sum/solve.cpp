#include <bits/stdc++.h>
#include "threeSum.h"

using namespace std;

int main()
{
    Solution a;

    vector<int> b = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> v = a.threeSum(b);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}