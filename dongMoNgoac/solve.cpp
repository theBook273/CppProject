#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string s;

    cin >> s;

    stack<char> st;

    bool check = 0;

    if (s.size() < 2)
    {
        return 0;
    }

    for (long long i = 0; i < s.size(); i++)
    {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(')
        {
            st.push(s[i]);
        }

        if (s[i] == ']' || s[i] == '}' || s[i] == ')')
        {

            check = 1;

            char temp = st.top();

            if (st.empty())
            {
                return 0;
            }

            st.pop();

            if (temp + 1 != s[i] && temp + 2 != s[i])
            {
                return 0;
            }
        }
    }

    return st.empty();
}
