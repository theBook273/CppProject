#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int close, open, dem;
    vector<string> ans;

public:
    void parenthesis(int close, int open, string parent)
    {
        if (close == open && open == 0)
        {
            ans.push_back(parent);
        }
        else
        {
            if (open > 0)
            {
                parent += "(";
                parenthesis(close, open - 1, parent);
                parent.pop_back();
            }

            if (close > 0 && close > open)
            {
                parent += ")";
                parenthesis(close - 1, open, parent);
                parent.pop_back();
            }
        }
    }

    vector<string> generateParenthesis(int n)
    {
        close = n;
        open = n - 1;
        dem = n;

        parenthesis(close, open, "(");

        return ans;
    }
};