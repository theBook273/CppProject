#include <bits/stdc++.h>

using namespace std;

class solution
{
private:
    string s, res;
    stack<char> st;

public:
    solution()
    {
        cin >> s;
    }

    string solve()
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '<')
            {
                if (!res.empty())
                {
                    st.push(res[res.size() - 1]);
                    res.pop_back();
                }
            }
            else if (s[i] == '>')
            {
                if (!st.empty())
                {
                    res.push_back(st.top());
                    st.pop();
                }
            }
            else if (s[i] == '-')
            {
                if (!res.empty())
                {
                    res.pop_back();
                }
            }
            else
            {
                res.push_back(s[i]);
            }
        }

        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};

int main()
{
    solution a;
    cout << a.solve() << endl;
    return 0;
}