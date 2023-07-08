#include <bits/stdc++.h>

using namespace std;

long long a;

long long gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    cin >> a;

    long long t = lcm(1, 2);

    for (int i = 3; i <= a; i++)
    {
        t = lcm(t, i) % int(1e9 + 7);
    }

    cout << t;
}