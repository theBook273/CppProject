#include <bits/stdc++.h>
#include "generate.h"

using namespace std;

long long main()
{
    Solution a;
    vector<string> v = a.generateParenthesis(3);

    for (string i : v)
    {
        cout << i << " ";
    }
}
