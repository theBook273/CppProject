#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    stack<int> st;

    cin >> n;

    while (n != 0)
    {
        st.push(n % 2);
        n /= 2;
    }

    while (!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}