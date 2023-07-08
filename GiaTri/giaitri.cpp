#include<bits/stdc++.h>

using namespace std;

string s;
vector<int> v;
long long k;

int main()
{
    cin >> s >> k;

    for(char i : s)
    {
        if('0' <= i && i <= '9')
        {
            v.push_back(i - '0');
        }
    }

    for(int i = 1; i <= k; i++)
    {
        cout << *max_element(v.begin(),v.end());
    }
}
