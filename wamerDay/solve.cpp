#include <bits/stdc++.h>
#include "warm.h"

using namespace std;

int main()
{
    Solution a;

    vector<int> v = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> temp = a.dailyTemperatures(v);

    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}