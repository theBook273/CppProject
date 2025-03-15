#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> tokens;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;

        cin >> temp;

        tokens.push_back(temp);
    }

    stack<int> st;

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
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(a * b);
            }
            if (i == "/")
            {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(b / a);
            }
            if (i == "+")
            {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(a + b);
            }
            if (i == "-")
            {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                st.push(b - a);
            }
        }
    }

    return (int)st.top();
}