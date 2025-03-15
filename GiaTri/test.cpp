#include<bits/stdc++.h>

using namespace std;

long long a,b,tong(0);
vector<long long >v;

bool check(int n)
{
    for(int i(2); pow(i,2) <= n; i++)
    {
        if(n % (int)pow(i,2) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{


    cin >> a >> b;

    for(int i(a); i <= b; i++)
    {
        for(int j(i+1); j <= b; j++)
        {
            if(check(i * j))
            {
                tong ++;
            }
        }
    }

    cout << tong;
}
