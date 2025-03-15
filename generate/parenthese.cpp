#include <bits/stdc++.h>
#include "generate.h"

using namespace std;

int main()
{
    Solution a;
    vector<string> v = a.generateParenthesis(3);

    for (string i : v)
    {
        cout << i << " ";
    }
}