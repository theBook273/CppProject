#include<bits/stdc++.h>

using namespace std;

long long l, r, tong = 0;
string k;

int main()
{
    cin >> k >> l >> r;

    for(int i = l; i <= r; i++)
    {
        if(to_string(i).find(k) != -1)
        {
            tong++;
        }
    }

    cout << tong;
}
