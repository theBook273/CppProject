#include <bits/stdc++.h>

using namespace std;

long long main()
{
    vector<string> tokens;

    long long n;

    cin >> n;

    for (long long i = 0; i < n; i++)
    {
        string temp;

        cin >> temp;

        tokens.push_back(temp);
    }

    stack<long long> st;

    for (auto i : tokens)
    {
        if (i.size() > 1 || isdigit(i[0]))
        {
            st.push(stoi(i));
        }
        else
        {

            if (i == "*")
            {
                long long a = st.top();
                st.pop();

                long long b = st.top();
                st.pop();

                st.push(a * b);
            }
            if (i == "/")
            {
                long long a = st.top();
                st.pop();

                long long b = st.top();
                st.pop();

                st.push(b / a);
            }
            if (i == "+")
            {
                long long a = st.top();
                st.pop();

                long long b = st.top();
                st.pop();

                st.push(a + b);
            }
            if (i == "-")
            {
                long long a = st.top();
                st.pop();

                long long b = st.top();
                st.pop();

                st.push(b - a);
            }
        }
    }

    return (long long)st.top();
}
