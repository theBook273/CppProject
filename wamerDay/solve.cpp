#include <bits/stdc++.h>
#include "warm.h"

using namespace std;

long long main()
{
    Solution a;

    vector<long long> v = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<long long> temp = a.dailyTemperatures(v);

    for (long long i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }
}
