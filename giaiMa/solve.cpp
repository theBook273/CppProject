#include <bits/stdc++.h>

using namespace std;
int n, k, dem = 0;
char temp[3] = {'L', 'Q', 'D'};
string s, res;

void create(int k)
{
    for (int i = 0; i < k; i++)
    {
        res += temp[0];
    }

    for (int i = 0; i < k; i++)
    {
        res += temp[1];
    }

    for (int i = 0; i < k; i++)
    {
        res += temp[2];
    }
}

int main()
{
    cin >> n >> k >> s;

    cout << n - k * 3;
}