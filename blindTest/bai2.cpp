#include<bits/stdc++.h>
#define int long long

using namespace std;

main()
{
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;

    while(t--)
    {
        string s;
        cin >> s;

        reverse(s.begin(),s.end());

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'q') s[i] = 'p';
            else if(s[i] == 'p') s[i] = 'q';
        }

        cout << s << endl;
    }
}
