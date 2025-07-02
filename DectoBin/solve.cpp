#include <bits/stdc++.h>

using namespace std;

long long main()
{
    long long n;
    stack<long long> st;

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
