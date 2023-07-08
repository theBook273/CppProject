#include <bits/stdc++.h>

using namespace std;

string solve(string s)
{
    string res;
    deque<char> d;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '<' && !res.empty())
        {
            d.push_back(res[res.size() - 1]);
            res.pop_back();
        }
        else if (s[i] == '>' && !res.empty() && !d.empty())
        {
            res += d.back();
            d.pop_back();
        }
        else if (s[i] == '-' && !res.empty())
        {
            res.pop_back();
        }
        else if (('0' <= s[i] && s[i] <= '9') || ('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z'))
        {
            res += s[i];
        }
    }

    if (!d.empty())
    {
        while (!d.empty())
        {
            res += d.back();
            d.pop_back();
        }
    }

    return res;
}

int main()
{
    string s;

    cin >> s;

    cout << solve(s);
}