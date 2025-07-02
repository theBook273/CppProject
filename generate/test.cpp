#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void prlong longParenthesis(long long ind, vector<string> &v, long long n, long long open, long long close, string &s)
    {
        if (ind == n)
        {                   // base case
            v.push_back(s); // we add final string to vector v
            return;         // we return back the control to function
        }

        if (open > 0 && ind != n - 1)
        {                                                        // we take "("
            s += "(";                                            // adding "(" to string s
            prlong longParenthesis(ind + 1, v, n, open - 1, close, s); // recursive function call
            s.pop_back();                                        // we have to take out "(" before returning the control to prev function.
        }

        if (close > 0 && open < close)
        {
            s += ")";
            prlong longParenthesis(ind + 1, v, n, open, close - 1, s);
            s.pop_back();
        }

        return;
    }
    vector<string> generateParenthesis(long long n)
    {
        vector<string> v;
        long long open = n - 1;
        long long close = n;
        n *= 2;
        string s = "(";

        prlong longParenthesis(1, v, n, open, close, s);

        return v;
    }
};
