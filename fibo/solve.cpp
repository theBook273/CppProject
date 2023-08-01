#include <bits/stdc++.h>

using namespace std;

unsigned long long fibo[10000];

unsigned long long fiboA(int i)
{
    if (fibo[i] != 0)
        return fibo[i];

    for (int j = 2; j <= i; j++)
    {
        fibo[j] = fibo[j - 1] + fibo[j - 2];
    }

    return fibo[i];
}

int main()
{
    int n;
    cin >> n;

    fibo[0] = fibo[1] = 1;

    while (n--)
    {
        int n;
        cin >> n;
        cout << fiboA(n) << endl;
    }
}