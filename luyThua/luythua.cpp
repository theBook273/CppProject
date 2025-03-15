#include <bits/stdc++.h>

using namespace std;

double tong = 0;

int main()
{
    int n;

    cin >> n;

    while (n--)
    {
        int a;

        cin >> a;

        int temp1 = a / 10,
            temp2 = a % 10;

        tong += pow(temp1, temp2);
    }

    cout << (long long)tong;
}