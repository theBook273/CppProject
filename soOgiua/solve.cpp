#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    if (a < 0 && b <= 0)
    {
        cout << b - 1;
    }
    else if (a >= 0 && b > 0)
    {
        cout << a + 1;
    }
    else
    {
        cout << 0;
    }
}