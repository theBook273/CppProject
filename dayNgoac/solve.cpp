#include <bits/stdc++.h>

using namespace std;

long long main()
{
    string s;

    stack<char> st;

    cin >> s;

    for (long long i = 0; i < s.length(); i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            cout << "KHONG HOP LE";
            return 0;
        }

        if (s[i] == '(')
        {
            if (i + 1 >= s.length())
            {
                cout << "KHONG DUNG";
                return 0;
            }
            st.push(s[i]);
        }

        if (s[i] == ')')
        {
            if (st.empty())
            {
                cout << "KHONG DUNG";
                return 0;
            }
            if (st.top() == '(')
            {
                st.pop();
            }
        }
    }

    cout << "DUNG";
}
