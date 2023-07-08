#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    while (n--)
    {
        string s;
        double a, b, c;
        cin >> a >> b >> c;

        b = a + b;
        a = max(a, b - a);
        b = b - a;

        if (a + b == c)
        {
            s += "+";
        }
        if (a - b == c)
        {
            s += "-";
        }
        if (a * b == c)
        {
            s += "*";
        }
        if (a / b == c)
        {
            s += "/";
        }
        if (s.empty())
        {
            cout << "?";
        }
        cout << s << "\n";
    }
}